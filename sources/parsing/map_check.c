/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:15:55 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/07 14:22:14 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	charschecker(const char **map)
{
	int	startflag;
	int	i;
	int	j;

	startflag = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_forbidden(map[i][j])
				|| (is_player_orientation(map[i][j]) && startflag))
				return (1);
			if (is_player_orientation(map[i][j]) && !startflag)
				startflag = 1;
			j++;
		}
		i++;
	}
	return (0);
}

int check_mapsize(const char **map)
{
	int area;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (map[0][j])
		j++;
	area = i * j;
	if (area > 5000)
		return (0);
	return (1);
}

static int is_empty(const char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if(!is_whitespace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int checklines(const char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_empty(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int mapchecker(const char **map)
{
	if (charschecker(map))
		return (err_int("Forbidden char\n", 0));
	if (!check_mapsize(map))
		return (err_int("Map is too big\n", 0));
	if (!checklines(map))
		return (err_int("Multiple maps\n", 0));
	return (1);
}

