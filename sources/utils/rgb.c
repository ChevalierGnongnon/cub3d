/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 12:40:21 by chhoflac          #+#    #+#             */
/*   Updated: 2025/02/01 12:44:08 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	rgb_checker(const char *srgb)
{
	int	i;

	i = 0;
	while (srgb[i])
	{
		if (srgb[i] == ',')
		{
			if (srgb[i + 1] == ',')
				return (0);
			i++;
			while (is_whitespace(srgb[i]))
				i++;
			if (srgb[i] == ',')
				return (0);
		}
		else if (!ft_isdigit(srgb[i]) && !is_whitespace(srgb[i])
			&& srgb[i] != ',')
			return (0);
		i++;
	}
	return (1);
}

int	rgb_check(t_rgb *rgb)
{
	if (rgb->red < 0 || rgb->red > 255)
		return (0);
	if (rgb->green < 0 || rgb->green > 255)
		return (0);
	if (rgb->blue < 0 || rgb->blue > 255)
		return (0);
	if (rgb->alpha < 0 || rgb->alpha > 255)
		return (0);
	return (1);
}
