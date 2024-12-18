/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:28 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/18 12:20:28 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	file_check(t_file *file)
{
	if (!file)
		return (ft_putstr_fd("Error:\n Memory allocation went wrong.", 2), 0);
	if (!file->path_north)
		return (ft_putstr_fd("Error:\n North texture is missing.", 2), 0);
	if (!file->path_south)
		return (ft_putstr_fd("Error:\n South texture is missing.", 2), 0);
	if (!file->path_west)
		return (ft_putstr_fd("Error:\n West texture is missing.", 2), 0);
	if (!file->path_east)
		return (ft_putstr_fd("Error:\n East texture is missing.", 2), 0);
	if (!file->rgb_ground)
		return (ft_putstr_fd("Error:\n Ground rgb is missing.", 2), 0);
	if (!file->rgb_sky)
		return (ft_putstr_fd("Error:\n Sky rgb is missing.", 2), 0);
	return (mapchecker(file->map));
}