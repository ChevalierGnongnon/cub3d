/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:54:00 by lahlsweh          #+#    #+#             */
/*   Updated: 2025/01/22 16:13:43 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_extension(char *map_path)
{
	int	size;

	size = ft_strlen(map_path);
	if (size >= 5 && (map_path[size - 1] == 'b' && map_path[size - 2] == 'u'
			&& map_path[size - 3] == 'c' && map_path[size - 4] == '.'))
		return (1);
	return (0);
}

void	launch(char *path)
{
	t_file	*process;
	mlx_t	*mlx;
	int		fd;

	if (file_check_textures(path) && file_check_rgb(path))
	{
		fd = open(path, O_RDONLY);
		if (fd == -1)
			ft_putstr_fd("error: map not existing\n", 2);
		else
		{
			process = file_process(fd);
			if (process)
			{
				flood_fill_process(process);
				mlx = mlx_init(130, 130, "gratfwetuwftvr", true);
				if (!mlx)
					return (ft_putstr_fd("Error", 2));
				get_graphics(process);
				free_file(process);
			}
			else
				err_null("File elements are not valid.\n");
			close(fd);
		}
	}
	else
		err_null("File elements are not valid.\n");
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (ft_putstr_fd("Error : map path needed\n", 2), 0);
	else if (argc > 2)
		return (ft_putstr_fd("Error : too many arguments\n", 2), 0);
	else
	{
		if (check_extension(argv[1]))
			launch(argv[1]);
		else
			ft_putstr_fd("error : wrong extension\n", 2);
	}
	return (0);
}
