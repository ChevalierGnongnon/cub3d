/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:17:28 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/15 15:43:51 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	*file_elements_not_valid(void)
{
	ft_putstr_fd("Error : file elements are not valid !", 2);
	return (NULL);
}

void	*not_enough_elements(void)
{
	ft_putstr_fd("Error: one or more elements are missing for parsing", 2);
	return (NULL);
}

void	*multiple_starting_pos(void)
{
	ft_putstr_fd("Error : forbidden char or multiple starting position", 2);
	return (NULL);
}