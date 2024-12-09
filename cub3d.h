/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:26:43 by lahlsweh          #+#    #+#             */
/*   Updated: 2024/12/06 14:56:43 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "libft/sources/libft.h"

typedef struct s_graphics
{
	mlx_image_t	*wall_south;
	mlx_image_t	*wall_north;
	mlx_image_t *wall_west;
	mlx_image_t *wall_east;
	mlx_image_t *ground;
	mlx_image_t	*sky;
}	t_img;

typedef struct s_file
{
	char	**map;
	int		player_start_posX;
	int		player_start_posY;
	char	*path_north;
	char	*path_south;
	char	*path_east;
	char	*path_west;
	char	*rgb_ground;
	char	*rgb_sky;
}	t_file;

typedef struct player
{
	int	pos_x;
	int	pos_y;
}	t_player;

/*
 * PARSING
 */
char	*get_value(char *line, size_t start);
t_file	*file_process(int fd);
void	get_rgb(t_file *file, char *line, char *key /*, int *flag*/);

/*
 * ERRORS
 */
void	*file_elements_not_valid(void);
void	*not_enough_elements(void);

/*
 * CHAR UTILS
 */
int		is_whitespace(char c);

/*
 * STRING UTILS
 */
int		ft_strcmp(const char *s1, const char *s2);

#endif
