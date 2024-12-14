/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:18:35 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/14 15:36:29 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	*free_map(const char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free((void *) map[i]);
		i++;
	}
	free((void *) map);
	return (NULL);
}

void	*free_file(t_file *file)
{
	if (file->map)
		free_map(file->map);
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
