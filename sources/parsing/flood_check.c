/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:44:48 by chhoflac          #+#    #+#             */
/*   Updated: 2025/02/01 16:45:45 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_bordline(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '2')
			return (0);
		i++;
	}
	return (1);
}

int	check_borders(char **map)
{
	int	i;

	i = 0;
	if (!check_bordline(map[i]))
		return (0);
	while (i < map_size((const char **) map) - 1)
	{
		if (map[i][0] == '2' || map[i][ft_strlen(map[i]) - 1] == '2')
			return (0);
		i++;
	}
	if (!check_bordline(map[i]))
		return (0);
	return (1);
}