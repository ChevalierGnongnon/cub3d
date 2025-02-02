/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:18:35 by chhoflac          #+#    #+#             */
/*   Updated: 2025/02/02 13:08:56 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	*free_two_dimentional(const char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return (NULL);
	if (map[i] == NULL)
		return (free(map), NULL);
	while (map[i])
	{
		free((void *) map[i]);
		i++;
	}
	free((void *) map);
	return (NULL);
}

void	*free_graphics(t_graphics *graphics)
{
	if (graphics->wall_east)
		mlx_delete_texture(graphics->wall_east);
	if (graphics->wall_south)
		mlx_delete_texture(graphics->wall_south);
	if (graphics->wall_north)
		mlx_delete_texture(graphics->wall_north);
	if (graphics->wall_west)
		mlx_delete_texture(graphics->wall_west);
	return (NULL);
}

void	*free_data(t_data *data)
{
	if (data->map)
		free_two_dimentional(data->map);
	if (data->path_east)
		free((void *) data->path_east);
	if (data->path_north)
		free((void *) data->path_north);
	if (data->path_south)
		free((void *) data->path_south);
	if (data->path_west)
		free((void *) data->path_west);
	if (data->rgb_ground)
		free((void *) data->rgb_ground);
	if (data->rgb_sky)
		free((void *) data->rgb_sky);
	free(data);
	return (NULL);
}

void	*free_all(mlx_t *mlx, t_data *data, t_graphics *graphics)
{
	if (data)
		free_data(data);
	if (graphics)
		free_graphics(graphics);
	if (mlx)
		mlx_terminate(mlx);
	return (NULL);
}
