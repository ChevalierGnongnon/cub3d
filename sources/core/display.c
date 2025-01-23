/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:24:35 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/23 14:25:15 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	display_process(t_file *file)
{
	int	i;

	i = 0;
	printf("----Textures----\n");
	printf("East: %s\n", file->path_east);
	printf("North: %s\n", file->path_north);
	printf("South: %s\n", file->path_south);
	printf("West: %s\n", file->path_west);
	printf("----RGB----\n");
	printf("Ground: %s\n", file->rgb_ground);
	printf("Sky: %s\n", file->rgb_sky);
	printf("----Map----\n");
	if (file->map[i])
	{
		while (file->map[i])
		{
			printf("%s\n", file->map[i]);
			i++;
		}
	}
}
