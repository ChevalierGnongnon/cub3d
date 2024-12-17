/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:26:43 by lahlsweh          #+#    #+#             */
/*   Updated: 2024/12/17 15:37:49 by chhoflac         ###   ########.fr       */
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
// # include <X11/keysym.h>
// # include <X11/X.h>
// # include "./MLX42/include/MLX42/MLX42.h"
# include "libft/sources/libft.h"

// typedef struct s_graphics
// {
// 	mlx_image_t	*wall_south;
// 	mlx_image_t	*wall_north;
// 	mlx_image_t *wall_west;
// 	mlx_image_t *wall_east;
// 	mlx_image_t *ground;
// 	mlx_image_t	*sky;
// }	t_img;

typedef struct s_file
{
	const char	**map;
	int			player_start_posX;
	int			player_start_posY;
	const char	*path_north;
	const char	*path_south;
	const char	*path_east;
	const char	*path_west;
	const char	*rgb_ground;
	const char	*rgb_sky;
}	t_file;

typedef struct player
{
	int	pos_x;
	int	pos_y;
}	t_player;

/*
 * PARSING
 */
const char	*get_value(char *line, char *key, size_t start, int *count);
t_file		*file_process(int fd);
const char	**map_recup(int fd);

/*
 * FREE
 */
void		*free_map(const char **map);
void		*free_file(t_file *file);

/*
 * PARSING ERRORS
 */
void		*file_elements_not_valid(void);
void		*not_enough_elements(void);
void		*multiple_starting_pos(void);

/*
 * CHAR UTILS
 */
int			is_whitespace(char c);

/*
 * STRING UTILS
 */
int			ft_strcmp(const char *s1, const char *s2);

/*
 * MAP UTILS 
 */
const char *dup_line(const char *line);
int			map_size(const char **map);

/*
 * FILE UTILS
 */
int			file_check_textures(char *path);
int			file_check_rgb(char *path);

/*
 * DISPLAY
 */
void		display_process(t_file *file);

#endif
