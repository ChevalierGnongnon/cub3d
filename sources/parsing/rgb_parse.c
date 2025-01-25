/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:37:38 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/25 17:17:52 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	rgb_checker(const char *srgb)
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
		else if (!ft_isdigit(srgb[i]) && !is_whitespace(srgb[i]) && srgb[i] != ',')
			return (0);
		i++;
	}
	return (1);
}

int value_checker(const char **trgb)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (trgb[i])
	{
		j = 0;
		while (trgb[i][j] && is_whitespace(trgb[i][j]))
			j++;
		while (trgb[i][j] && ft_isdigit(trgb[i][j]))
			j++;
		while (trgb[i][j])
		{
			if (!is_whitespace(trgb[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static t_rgb *rgb_get(const char *srgb)
{
	const char	**trgb;
	t_rgb		*rgb;
	int			i;
	
	i = 0;
	trgb = ft_split(srgb, ',');
	if (!trgb)
		return (NULL);
	if (!value_checker(trgb))
		return (free_two_dimentional(trgb));
	if (map_size(trgb) > 4 || map_size(trgb) < 3)
		return (NULL);
	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		return (free_two_dimentional(trgb));
	rgb->red = ft_atou(trgb[0]);
	rgb->green = ft_atou(trgb[1]);
	rgb->blue = ft_atou(trgb[2]);
	if (map_size(trgb) == 4)
		rgb->alpha = ft_atou(trgb[3]);
	else
		rgb->alpha = 255;
	free_two_dimentional(trgb);
	return (rgb);
}

int rgb_check(t_rgb *rgb)
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

unsigned int rgb_convert(const char *srgb)
{
	t_rgb			*rgb;
	unsigned int 	value;

	if (!srgb)
		return (err_int("rgb entry is missing or invalid.", -1));
	if (rgb_checker(srgb))
	{
		rgb = rgb_get(srgb);
		if (!rgb)
			return (err_int("rgb entry is missing or invalid.", -1));
		if (!rgb_check(rgb))
		{
			free(rgb);
			return (err_int("rgb entry is missing or invalid.", -1));
		}
		value = 0;
		value += rgb->red << 24 | rgb->green << 16 | rgb->blue << 8 | rgb->alpha;
		free(rgb);
		printf("%x\n", value);
		return (value);
	}
	return (err_int("rgb entry is missing or invalid.\n", -1));
}
