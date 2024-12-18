/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:52:47 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/18 12:17:40 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	find_key(char *line)
{
	char	*key;
	int		i;

	i = 0;
	if (line[i] == ' ' || line[i] == '\t')
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

void	set_img_paths(t_file *file, char *line, int *flag)
{
	char		*key;
	size_t		i;
	static int	cnt = 0;

	i = 0;
	if (line[i] == ' ' || line[i] == '\t')
		i++;
	key = ft_substr(line, i, 2);
	if (!key)
		return ;
	if (key[0] == 'F' && is_whitespace(key[1]))
		file->rgb_ground = get_value(line, key, i, &cnt);
	if (key[0] == 'C' && is_whitespace(key[1]))
		file->rgb_sky = get_value(line, key, i, &cnt);
	if (!ft_strcmp("NO", key))
		file->path_north = get_value(line, key, i, &cnt);
	else if (!ft_strcmp("SO", key))
		file->path_south = get_value(line, key, i, &cnt);
	else if (!ft_strcmp("WE", key))
		file->path_west = get_value(line, key, i, &cnt);
	else if (!ft_strcmp("EA", key))
		file->path_east = get_value(line, key, i, &cnt);
	if (cnt == 6)
		(*flag) = 1;
	free(key);
}

void	file_preset(t_file *file)
{
	file->map = NULL;
	file->path_east = NULL;
	file->path_north = NULL;
	file->path_south = NULL;
	file->path_west = NULL;
	file->player_start_posX = 0;
	file->player_start_posX = 0;
	file->rgb_ground = NULL;
	file->rgb_sky = NULL;
}

void	*file_not_valid(t_file *file, char *line)
{
	free(line);
	free_file(file);
	file_elements_not_valid();
	return (NULL);
}

t_file	*file_process(int fd)
{
	char	*line;
	int		flag;
	t_file	*file;

	flag = 0;
	file = ft_calloc(1, sizeof(t_file));
	if (!file)
		return (NULL);
	file_preset(file);
	line = get_next_line(fd);
	if (line && find_key(line))
		set_img_paths(file, line, &flag);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if (line && find_key(line))
			set_img_paths(file, line, &flag);
		else if ((line && !find_key(line) && !flag))
			return (file_not_valid(file, line));
		else if (flag && line)
			file->map = map_recup(fd);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (!file->map)
		return (free_file(file));
	if (!file_check(file))
		return (NULL);
	return (file);
}
