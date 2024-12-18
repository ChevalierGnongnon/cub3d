/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:17:28 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/18 12:25:25 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	*file_elements_not_valid(void)
{
	ft_putstr_fd("Error:\n file elements are not valid !", 2);
	return (NULL);
}

void	*multiple_starting_pos(void)
{
	ft_putstr_fd("Error: forbidden char or multiple starting position", 2);
	return (NULL);
}
