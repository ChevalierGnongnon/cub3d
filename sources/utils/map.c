/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:15:05 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/09 16:07:00 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

const char	*dup_line(const char *line)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(sizeof(char), ft_strlen(line) + 1);
	if (!new)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	map_size(const char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int get_widthmax(const char **map)
{
	size_t	max;
	int 	i;

	i = 0;
	max = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

char	**flood_fill_copy(const char **map)
{
	char	**copy;
	int		max;
	int		i;
	int		j;
	int		k;
	
	i = 0;
	k = 0;
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
		while (map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}
		while (j < max)
		{
			copy[i][j] = ' ';
			j++;
		} 
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

const char **map_chunk(const char **map)
{
	const char	**chunked;
	int			size;
	int			i;

	size = 0;
	i = 0;
	while (map[i] && !is_empty(map[i]))
	{
		size++;
		i++;
	}
	chunked = ft_calloc(sizeof(char *), size + 1);
	if (!chunked)
		return (NULL);
	i = 0;
	while (i < size)
	{
		chunked[i] = ft_strdup(map[i]);
		i++;
	}
	chunked[i] = NULL;
	return (chunked);
}

void	line_copy(const char **map, char **copy, int *j, int i)
{
	while (map[i][(*j)])
	{
		copy[i][(*j)] = map[i][(*j)];
		(*j)++;
	}
}

void	fill_with_spaces(const char **map, char **copy, int j, int i)
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
