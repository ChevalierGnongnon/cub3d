/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:28 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/07 14:55:09 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	file_check_values(t_file *file)
{
	if (!file)
		return (err_int("Memory allocation went wrong.\n", 0));
	if (!file->path_north)
		return (err_int("North texture is missing or invalid.\n", 0));
	if (!file->path_south)
		return (err_int("South texture is missing or invalid.\n",0));
	if (!file->path_west)
		return (err_int("West texture is missing or invalid.\n", 0));
	if (!file->path_east)
		return (err_int("East texture is missing or invalid.\n", 0));
	if (!file->map)
		return (err_int("Map is missing or invalid.\n", 0));
	// if (!file->rgb_ground || !rgb_check(file->rgb_ground))
	// 	return (ft_putstr_fd
	// 		("Error:\n Ground rgb is missing or in the wrong shape.\n", 2), 0);
	// if (!file->rgb_sky || !rgb_check(file->rgb_sky))
	// 	return (ft_putstr_fd
	// 		("Error:\n Sky rgb is missing or in the wrong shape.\n", 2), 0);
	return (1);
}
