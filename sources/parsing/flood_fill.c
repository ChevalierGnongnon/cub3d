/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:27:27 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/08 15:25:23 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
				file->player_start_posX = i;
				file->player_start_posY = j;
			}
			j++;
		}
		i++;
	}
}

int	is_accessible(char element)
{
	if (is_whitespace(element))
		return (-1);
	if (element == '1' || element == '2')
		return (0);
	return (1);
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

int check_bordline (const char *line)
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

static int check_borders(char **map)
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

int	flood_fill_process(t_file *file)
{
	t_pos	pos;
	char	**copy;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	copy = map_copy(file->map);
	if (!copy)
		return (0);
	get_start_position(copy, file);
	pos.x = file->player_start_posX;
	pos.y = file->player_start_posY;
	flood_fill(pos, copy, &flag);
	if (flag == -1 || !check_borders(copy))
	{
		ft_putstr_fd("Error:\n Map has holes\n", 2);
		free_map((const char **) copy);
		return (0);
	}
	free_map((const char **) copy);
	return (1);
}
