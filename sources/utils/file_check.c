/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:41:38 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/14 12:53:21 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	find_key_texture(char *line)
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
	return (0);
}

static int	find_key_rgb(char *line)
{
	char	*key;
	int		i;

	i = 0;
	if (line[i] == ' ' || line[i] == '\t')
		i++;
	key = ft_substr(line, i, 2);
	if (!key)
		return (0);
	if ((!ft_strcmp("F", key) || !ft_strcmp("C", key))
		&& (line[i + 1] || is_whitespace(line[i + 1])))
		return (free(key), 1);
	free(key);
	return (0);
}

int	file_check_textures(char *path)
{
	int		fd;
	int		cnt;
	char	*line;
	
	fd = open(path, O_RDONLY);
	cnt = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line && find_key_texture(line))
			cnt++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	if (cnt > 4)
		return (0);
	return (1);
}

int	file_check_rgb(char *path)
{
	int		fd;
	int		cnt;
	char	*line;
	
	fd = open(path, O_RDONLY);
	cnt = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line && find_key_rgb(line))
			cnt++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (cnt > 1)
		return (0);
	return (1);
}
