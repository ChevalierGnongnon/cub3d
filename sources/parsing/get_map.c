/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:15:37 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/11 16:02:48 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	map_size(const char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

static const char	**map_edit(const char **map, char *line)
{
	const char	**new_map;
	int			i;
	
	i = 0;
	new_map = malloc(map_size(map) + 2);
	if(!new_map)
		return (NULL);
	while (map[i] != NULL)
	{
		new_map[i] = dup_line(map[i]);
		if (!new_map)
			return (NULL);
		i++;
		free((void *) map[i]);
	}
	new_map[i] = dup_line(line);
	new_map[i + 1] = NULL;
	free((void *) map);
	return (new_map);
}

const char	**map_recup(int fd)
{
	const char	**map;
	char		*line;

	map = ft_calloc(2, 1);
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line == NULL)
		line = get_next_line(fd);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		map = map_edit(map, line);
		if (!map)
			return (NULL);
		line = get_next_line(fd);
	}
	return (map);
}
