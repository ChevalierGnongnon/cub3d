/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:43:09 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/09 16:55:52 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	line_copy(const char **map, char **copy, int *j, int i)
{
	while (map[i][(*j)])
	{
		copy[i][(*j)] = map[i][(*j)];
		(*j)++;
	}
}

static void	fill_with_spaces(const char **map, char **copy, int j, int i)
{
	int max;
	
	max = get_widthmax(map);
	while (j < max)
	{
		copy[i][j] = ' ';
		j++;
	}
	copy[i][j] = '\0';
}

char	**flood_fill_copy(const char **map)
{
	char	**copy;
	int		max;
	int		i;
	int		j;
	
	i = 0;
	max = get_widthmax(map);
	copy = ft_calloc(sizeof(char *), map_size(map) + 1);
	if (!copy)
		return (NULL);
	while (map[i])
	{
		j = 0;
		copy[i] = ft_calloc(sizeof(char *), max);
		if (!copy[i])
			return (free_map((const char **) copy));
		line_copy(map, copy, &j, i);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

const char	**map_copy(const char **map)
{
	char		**copy;
	const char	**chunked;
	int			i;
	int			j;
	
	i = 0;
	copy = ft_calloc(sizeof(char *),  map_size(map) + 1);
	if (!copy)
		return (NULL);
	while (map[i])
	{
		j = 0;
		copy[i] = ft_calloc(sizeof(char *), get_widthmax(map) + 1);
		if (!copy[i])
			return (free_map((const char **) copy));
		line_copy(map, copy, &j, i);
		fill_with_spaces(map, copy, j, i);
		i++;
	}
	copy[i] = NULL;
	chunked = map_chunk((const char **) copy);
	if (!chunked)
		return (NULL);
	free_map((const char **) copy);
	return (chunked);
}
