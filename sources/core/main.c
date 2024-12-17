/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:54:00 by lahlsweh          #+#    #+#             */
/*   Updated: 2024/12/17 15:17:38 by chhoflac         ###   ########.fr       */
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
	// void	*mlx;
	int		fd;
	t_file	*process;
	
	if (file_check_textures(path) && file_check_rgb(path))
	{	
		fd = open(path, O_RDONLY);
		if (fd == -1)
			ft_putstr_fd("error: map not existing\n", 2);
		else
		{
			process = file_process(fd);
			display_process(process);
			close(fd);
			if (process)
				free_file(process);
		}
	}
	else
		file_elements_not_valid();
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
