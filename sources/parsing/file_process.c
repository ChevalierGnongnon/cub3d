/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:52:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/02/02 11:09:30 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	find_key(char *line)
{
	char	*key;
	int		i;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	key = ft_substr(line, i, 2);
	if (!key)
		return (0);
	if ((!ft_strcmp("NO", key) || !ft_strcmp("SO", key)
			|| !ft_strcmp("WE", key) || !ft_strcmp("EA", key))
		&& (line[i + 2] || is_whitespace(line[i + 2])))
		return (free(key), 1);
	free(key);
	key = ft_substr(line, i, 1);
	if ((!ft_strcmp("F", key) || !ft_strcmp("C", key))
		&& (line[i + 1] || is_whitespace(line[i + 1])))
		return (free(key), 1);
	free(key);
	return (0);
}

void	set_img_paths(t_data *data, char *line, int *flag)
{
	char		*key;
	size_t		i;
	static int	cnt = 0;

	i = 0;
	while (is_whitespace(line[i]))
		i++;
	key = ft_substr(line, i, 2);
	if (!key)
		return ;
	if (key[0] == 'F' && is_whitespace(key[1]))
		data->rgb_ground = get_value(line, key, i, &cnt);
	if (key[0] == 'C' && is_whitespace(key[1]))
		data->rgb_sky = get_value(line, key, i, &cnt);
	if (!ft_strcmp("NO", key))
		data->path_north = get_value(line, key, i, &cnt);
	else if (!ft_strcmp("SO", key))
		data->path_south = get_value(line, key, i, &cnt);
	else if (!ft_strcmp("WE", key))
		data->path_west = get_value(line, key, i, &cnt);
	else if (!ft_strcmp("EA", key))
		data->path_east = get_value(line, key, i, &cnt);
	if (cnt == 6)
		(*flag) = 1;
	free(key);
}

void	data_preset(t_data *data)
{
	data->map = NULL;
	data->path_east = NULL;
	data->path_north = NULL;
	data->path_south = NULL;
	data->path_west = NULL;
	data->player_start_posX = 0;
	data->player_start_posX = 0;
	data->rgb_ground = NULL;
	data->rgb_sky = NULL;
}

t_data	*dataset(t_data *data, int *flag, int fd)
{
	char	*line;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data_preset(data);
	line = get_next_line(fd);
	if (line && find_key(line))
		set_img_paths(data, line, flag);
	free(line);
	return (data);
}

t_data	*file_process(int fd)
{
	t_data	*data;
	char	*line;
	int		flag;
	int		k;

	flag = 0;
	data = NULL;
	data = dataset(data, &flag, fd);
	if (!data)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (line && find_key(line))
			set_img_paths(data, line, &flag);
		else if (line && !is_empty(line) && !find_key(line) && !flag)
		{
			free(line);
			free_all(NULL, data, NULL);
			return (err_null("data is invalid or inexistant"));
		}
		else if (flag && line)
		{
			while (line && is_empty(line))
			{
				free(line);
				line = get_next_line(fd);
			}
			if (!line)
				return (err_null("Map is missing"));
			data->map = map_recup(fd, line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	k = 0;
	while (data->map[k])
	{
		printf("%s\n", data->map[k]);
		k++;
	}
	if (!data->map)
	{
		free_data(data);
		return (err_null("Map is invalid or inexistant"));
	}
	free(line);
	return (data);
}
