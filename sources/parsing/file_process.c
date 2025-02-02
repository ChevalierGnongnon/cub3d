/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:52:47 by chhoflac          #+#    #+#             */
/*   Updated: 2025/02/02 16:39:22 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

char	*path_empty_lines(char *line, int fd)
{
	while (line && is_empty(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

t_file_process	file_process_init(int fd)
{
	t_file_process	file;

	file.flag = 0;
	file.data = dataset(&file.flag, fd);
	if (!file.data)
		return (file);
	file.line = get_next_line(fd);
	return (file);
}

t_data	*file_process_init_and_check(int fd, t_file_process *file)
{
	*file = file_process_init(fd);
	if (!file->data)
		return (NULL);
	return (file->data);
}

t_data	*file_process_loop(int fd, t_file_process *file)
{
	while (file->line)
	{
		if (file->line && find_key(file->line))
			set_img_paths(file->data, file->line, &file->flag);
		else if (file->line && !is_empty(file->line)
			&& !find_key(file->line) && !file->flag)
			return (error_handler(file->data, file->line));
		else if (file->flag && file->line)
		{
			file->line = path_empty_lines(file->line, fd);
			if (!file->line)
				return (err_null("Map is missing"));
			file->data->map = map_recup(fd, file->line);
			break ;
		}
		free(file->line);
		file->line = get_next_line(fd);
	}
	if (!file->data->map)
		return (free_data(file->data),
			err_null("Map is invalid or inexistant"));
	return (free(file->line), file->data);
}

t_data	*file_process(int fd)
{
	t_file_process	file;
	t_data			*data;

	data = file_process_init_and_check(fd, &file);
	if (!data)
		return (NULL);
	return (file_process_loop(fd, &file));
}
