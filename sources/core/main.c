/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:54:00 by lahlsweh          #+#    #+#             */
/*   Updated: 2025/02/02 13:11:10 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_extension(char *map_path)
{
	int	size;

	size = ft_strlen(map_path);
	
	if (size >= 5 && (map_path[size - 1] == 'b' && map_path[size - 2] == 'u'
			&& map_path[size - 3] == 'c' && map_path[size - 4] == '.'
			&& ft_isalnum(map_path[size - 5])))
		return (1);
	return (0);
}

void	launch(char *path)
{
	t_data		*data;
	t_graphics	*graphics;
	mlx_t		*mlx;
	int			fd;

	if (file_check_textures(path) && file_check_rgb(path))
	{
		fd = open(path, O_RDONLY);
		if (fd == -1)
			err_no_return("File is not existing");
		else
		{
			data = file_process(fd);
			if (data)
			{
				if (flood_fill_process(data))
				{
					mlx = mlx_init(130, 130, "gratfwetuwftvr", true);
					if (!mlx)
						return (err_no_return("MLX is not working / wasn't able to launch"));
					graphics = get_graphics(data);
					if (graphics)
						free_graphics(graphics);
					mlx_terminate(mlx);
				}
				free_all(NULL, data, NULL);
			}
			close(fd);
		}
	}
	else
		err_null("File elements are not valid.");
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		err_no_return("Arguments are not valid.");
	else if (argc > 2)
		err_no_return("Too many arguments");
	else
	{
		if (check_extension(argv[1]))
			launch(argv[1]);
		else
			err_no_return("Wrong file extension");
	}
}
