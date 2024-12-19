/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:15:05 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/19 13:56:08 by chhoflac         ###   ########.fr       */
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

char	**map_copy(const char **map)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	copy = ft_calloc(sizeof(char *), map_size(map) + 1);
	if (!copy)
		return (NULL);
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (free_map((const char **) copy));
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
