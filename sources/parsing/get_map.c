/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:15:37 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/23 14:46:13 by chhoflac         ###   ########.fr       */
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
			return (free_two_dimentional(map));
		i++;
	}
	new_map[i] = dup_line(line);
	new_map[i + 1] = NULL;
	free_two_dimentional(map);
	return (new_map);
}

const char	**map_recup(int fd, char *line)
{
	const char	**map;
	const char	**copy;
	char		*next;
	

	map = ft_calloc(2, sizeof(char *));
	if (!map)
		return (NULL);
	if (is_empty(line))
	{	
		while (is_empty(line))
		{
			free(line);
			line = get_next_line(fd);
		}
	}
	map = map_edit(map, line);
	if (!map)
		return (free_two_dimentional(map));
	next = get_next_line(fd);
	while (next)
	{
		map = map_edit(map, next);
		if (!map)
			return (free_two_dimentional(map));
		next = get_next_line(fd);
	}
	if (!mapchecker(map))
		return (NULL);
	copy = map_copy(map);
	free_two_dimentional(map);
	return (copy);
}
