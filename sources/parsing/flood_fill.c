/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:27:27 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/19 14:46:46 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// void	fill_holes(char **map)
// {
// 	int	i;
// 	int j;
	
// 	i = 0;
// 	j = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (is_whitespace(map[i][j]))
// 				map[i][j] = '1';
// 			j++;
// 		}
// 		i++;
// 	}
// }

static void	get_start_position(char **copy, t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (is_player_orientation(copy[i][j]))
			{
				file->player_start_posX = j;
				file->player_start_posY = i;
			}
			j++;
		}
		i++;
	}
}

int is_accessible(char element)
{
	if (element == 1 || element == 2)
		return (0);
	return (1);
}

void	flood_fill(t_pos pos, char **map)
{
	if (map[pos.x] && map[pos.x][pos.y]
		&& is_accessible(map[pos.x][pos.y]))
	{
		map[pos.x][pos.y] = '2';
		pos.x++;
		flood_fill(pos, map);
		pos.x -= 2;
		flood_fill(pos, map);
		pos.x++;
		pos.y++;
		flood_fill(pos, map);
		pos.y -= 2;
		flood_fill(pos, map);
	}
	else
	{
		pos.x++;
		pos.y++;
	}
}

char	**flood_fill_process(t_file *file)
{
	t_pos	pos;
	char	**copy;
	int		i;

	i = 0;
	copy = map_copy(file->map);
	if (!copy)
		return (NULL);
	get_start_position(copy, file);
	pos.x = file->player_start_posX;
	pos.y = file->player_start_posY;
	flood_fill(pos, copy);
	free_map((const char **) copy);
	return (copy);
}
