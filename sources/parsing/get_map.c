/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:15:37 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/10 16:20:06 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static const char	**map_edit(const char **map, char *line)
{
	const char	**new_map;
	int			i;
	
	i = 0;
	new_map = ft_calloc(sizeof(char *), map_size(map) + 2);
	if(!new_map)
		return (NULL);
	while (map[i] != NULL)
	{
		new_map[i] = dup_line(map[i]);
		if (!new_map)
			return (free_map(map));
		i++;
	}
	new_map[i] = dup_line(line);
	new_map[i + 1] = NULL;
	free_map(map);
	return (new_map);
}

const char	**map_recup(int fd)
{
	const char	**map;
	const char	**copy;
	char		*line;
	

	map = ft_calloc(2, sizeof(char *));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	printf("\n%s | %zu\n", line, ft_strlen(line));
	while (line == NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	map = map_edit(map, line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		map = map_edit(map, line);
		if (!map)
			return (NULL);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (!mapchecker(map))
		return (NULL);
	copy = map_copy(map);
	free_map(map);
	return (copy);
}
