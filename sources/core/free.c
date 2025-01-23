/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:18:35 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/23 15:21:51 by chhoflac         ###   ########.fr       */
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

void		*free_graphics(mlx_t *mlx, t_graphics *graphics)
{
	if (graphics->wall_east)
		mlx_delete_image(mlx, graphics->wall_east);
	if (graphics->wall_south)
		mlx_delete_image(mlx, graphics->wall_south);
	if (graphics->wall_north)
		mlx_delete_image(mlx, graphics->wall_north);
	if (graphics->wall_west)
		mlx_delete_image(mlx, graphics->wall_west);
	return (NULL);
}

void	*free_file(t_file *file)
{
	if (file->map)
		free_two_dimentional(file->map);
	if (file->path_east)
		free((void *) file->path_east);
	if (file->path_north)
		free((void *) file->path_north);
	if (file->path_south)
		free((void *) file->path_south);
	if (file->path_west)
		free((void *) file->path_west);
	if (file->rgb_ground)
		free((void *) file->rgb_ground);
	if (file->rgb_sky)
		free((void *) file->rgb_sky);
	free(file);
	return (NULL);
}
