/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:58:15 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/27 15:25:33 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int check_graphics(t_graphics *graphics)
{
	if (graphics->wall_east == NULL
		|| (graphics->wall_east->width !=  225 && graphics->wall_east->height !=  225))
		return (err_int("East wall is missing or in wrong shape", 0));
	if (graphics->wall_west == NULL
		|| (graphics->wall_west->width !=  225 && graphics->wall_west->height !=  225))
		return (err_int("West wall is missing or in wrong shape", 0));
	if (graphics->wall_north == NULL
		|| (graphics->wall_north->width !=  225 && graphics->wall_north->height !=  225))
		return (err_int("North wall is missing or in wrong shape", 0));
	if (graphics->wall_south == NULL
		|| (graphics->wall_south->width !=  225 && graphics->wall_south->height !=  225))
		return (err_int("South wall is missing or in wrong shape", 0));
	return (1);
}

static int	check_png_extension(const char *path)
{
	int	size;

	size = ft_strlen(path);
	if (size >= 5 && (path[size - 1] == 'g' && path[size - 2] == 'n'
			&& path[size - 3] == 'p' && path[size - 4] == '.'))
		return (1);
	return (0);
}

static mlx_image_t	*get_image(mlx_t *mlx, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	
	texture = mlx_load_png(path);
	if (!texture)
		return (NULL);
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		return (NULL);
	mlx_delete_texture(texture);
	return (image);
}

t_graphics	*get_graphics(mlx_t *mlx, t_file *file)
{
	t_graphics	*imgs;

	imgs = ft_calloc(1, sizeof(t_graphics));
	if (!imgs)
		return (NULL);
	imgs->wall_south = get_image(mlx, file->path_south);
	imgs->wall_north = get_image(mlx, file->path_north);
	imgs->wall_east = get_image(mlx, file->path_east);
	imgs->wall_west = get_image(mlx, file->path_west);
	imgs->sky = rgb_convert(file->rgb_sky);
	imgs->ground = rgb_convert(file->rgb_ground);
	if (!check_graphics(imgs))
		return (NULL);
	return (imgs);
}