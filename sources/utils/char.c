/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:54:59 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/10 18:23:13 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	return (0);
}

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int	is_player_orientation(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_forbidden(char c)
{
	if (c != '1' && c != '0' && !is_space(c) && !is_player_orientation(c))
		return (1);
	return (0);
}
