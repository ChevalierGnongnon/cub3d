/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:27:27 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/19 13:59:00 by chhoflac         ###   ########.fr       */
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

void	flood_fill(t_file *file)
{
	char	**copy;
	int		i;

	i = 0;
	copy = map_copy(file->map);
	if (!copy)
		return ;
	get_start_position(copy,file);
	printf("\n");
	while (copy[i])
	{
		printf("%s\n", file->map[i]);
		i++;
	}
	printf("X = %d\nY = %d\n", file->player_start_posX, file->player_start_posY);
	free_map((const char **) copy);
}
