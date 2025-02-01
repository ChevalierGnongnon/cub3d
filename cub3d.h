/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:26:43 by lahlsweh          #+#    #+#             */
/*   Updated: 2025/02/01 12:42:55 by chhoflac         ###   ########.fr       */
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
	mlx_image_t				*wall_south;
	mlx_image_t				*wall_north;
	mlx_image_t 			*wall_west;
	mlx_image_t				*wall_east;
	unsigned int			ground;
	unsigned int			sky;
}	t_graphics;

typedef struct s_rgb
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	unsigned int alpha;
}	t_rgb;

typedef struct s_pos
{
	int	x;
	int y;
}	t_pos;

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
}	t_data;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}	t_player;

/*
 * PARSING
 */
const char	*get_value(char *line, char *key, size_t start, int *count);
t_data		*file_process(int fd);
const char	**map_recup(int fd, char *line);
const char	**map_copy(const char **map);
char		**flood_fill_copy(const char **map);
int 		mapchecker(const char **map);
int			file_check_values(t_data *data);
void 		flood_fill(t_pos pos, char **map, int *flag);
int			flood_fill_process(t_data *data);
int 		get_widthmax(const char **map);

/*
 * Graphics
 */

t_graphics	*get_graphics(mlx_t *mlx, t_data *data);

/*
 * RGB
 */

unsigned int 		rgb_convert(const char *srgb, int *checker);

/*
 * FREE
 */
void		*free_two_dimentional(const char **map);
void		*free_data(t_data *data);
void		*free_graphics(mlx_t *mlx, t_graphics *graphics);
void		*free_all(mlx_t *mlx, t_data *data, t_graphics *graphics);

/*
 * PARSING ERRORS
 */
void		*err_null(const char *message);
int			err_int(const char *message, int err_num);
void		err_no_return(const char *message);
void		*file_not_valid(t_data *data, char *line);

/*
 * CHAR UTILS
 */
int			is_whitespace(char c);
int			is_player_orientation(char c);
int			is_forbidden(char c);

/*
 * STRING UTILS
 */

int				ft_strcmp(const char *s1, const char *s2);
unsigned int	ft_atou(const char *str);
/*
 * MAP UTILS 
 */
const char *dup_line(const char *line);
int			map_size(const char **map);
int 		is_empty(const char *line);
const char	**map_chunk(const char **map);

/*
 * FILE UTILS
 */
int			file_check_textures(char *path);
int			file_check_rgb(char *path);

/*
 * RGB UTILS
 */
int			rgb_checker(const char *srgb);
int			rgb_check(t_rgb *rgb);

/*
 * DISPLAY
 */
void		display_process(t_data *data);

#endif
