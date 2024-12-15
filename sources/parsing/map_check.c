/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:15:55 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/15 14:52:55 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>



int	charschecker(const char **map)
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
			if (is_forbidden(map[i][j]))
				return (1);
			if (is_player_orientation(map[i][j]) && startflag)
				return (0);
			if (is_player_orientation(map[i][j]) && !startflag)
				startflag = 1;
			j++;
		}
		i++;
	}
	return (1);
}
