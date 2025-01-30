/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:17:28 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/30 16:49:36 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	*err_null(const char *message)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

int	err_int(const char *message, int err_num)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	return (err_num);
}

void	err_no_return(const char *message)
{
	ft_putstr_fd("Error:\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
}

// void	*file_not_valid(t_data *data, char *line)
// {
// 	free(line);
// 	free_data(data);
// 	return (err_null("File elements are not valid.\n"));
// }
