/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:27:27 by chhoflac          #+#    #+#             */
/*   Updated: 2025/02/01 16:49:44 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	get_start_position(char **copy, t_data *data)
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
				data->player_start_posX = i;
				data->player_start_posY = j;
			}
			j++;
		}
		i++;
	}
}

void	check_other_zone(char **map, int *flag)
{
	t_pos	*pos;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				pos = ft_calloc(sizeof(t_pos), 1);
				if (!pos)
					(*flag) = -1;
				pos->x = i;
				pos->y = j;
				flood_fill((*pos), map, flag);
				free(pos);
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_pos pos, char **map, int *flag)
{
	int	check;

	if (pos.x >= 0 && pos.x <= map_size((const char **) map + 1))
	{
		check = is_accessible(map[pos.x][pos.y]);
		if (check == -1)
			(*flag) = -1;
		if (check != -1 && map[pos.x] && map[pos.x][pos.y]
			&& is_accessible(map[pos.x][pos.y]))
		{
			map[pos.x][pos.y] = '2';
			pos.x++;
			flood_fill(pos, map, flag);
			pos.x -= 2;
			flood_fill(pos, map, flag);
			pos.x++;
			pos.y++;
			flood_fill(pos, map, flag);
			pos.y -= 2;
			flood_fill(pos, map, flag);
		}
	}
	else
		(*flag) = -1;
}

int	flood_fill_process(t_data *data)
{
	t_pos	pos;
	char	**copy;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	copy = flood_fill_copy(data->map);
	if (!copy)
		return (0);
	get_start_position(copy, data);
	pos.x = data->player_start_posX;
	pos.y = data->player_start_posY;
	flood_fill(pos, copy, &flag);
	check_other_zone(copy, &flag);
	if (flag == -1 || !check_borders(copy))
	{
		free_two_dimentional((const char **) copy);
		return (err_int("Map has holes", 0));
	}
	free_two_dimentional((const char **) copy);
	return (1);
}
