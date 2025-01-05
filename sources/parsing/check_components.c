/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:28 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/05 16:37:40 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	file_check_values(t_file *file)
{
	if (!file)
		return (ft_putstr_fd("Error:\nMemory allocation went wrong.\n", 2), 0);
	if (!file->path_north)
		return (ft_putstr_fd("Error:\nNorth texture is missing.\n", 2), 0);
	if (!file->path_south)
		return (ft_putstr_fd("Error:\nSouth texture is missing.\n", 2), 0);
	if (!file->path_west)
		return (ft_putstr_fd("Error:\nWest texture is missing.\n", 2), 0);
	if (!file->path_east)
		return (ft_putstr_fd("Error:\nEast texture is missing.\n", 2), 0);
	if (!file->map)
		return (ft_putstr_fd("Error:\nMap is missing.\n", 2), 0);
	// if (!file->rgb_ground || !rgb_check(file->rgb_ground))
	// 	return (ft_putstr_fd
	// 		("Error:\n Ground rgb is missing or in the wrong shape.\n", 2), 0);
	// if (!file->rgb_sky || !rgb_check(file->rgb_sky))
	// 	return (ft_putstr_fd
	// 		("Error:\n Sky rgb is missing or in the wrong shape.\n", 2), 0);
	return (1);
}
