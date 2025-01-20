/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:37:38 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/20 15:24:31 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// static int alpha_check(const char *line)
// {
// 	int i; 
	
// 	i = 0;
// 	while (line[i])
// 	{
// 		// printf("'%c'\n", line[i]);
// 		if (!is_whitespace(line[i]) && !ft_isdigit(line[i])
// 			&& line[i] != ',')
// 			return (0);
// 		i++;
// 	}
// 	return(1);
// }

// static int get_rgb_value(const char *rgb_part)
// {
// 	char	*sub;
// 	int		value;
// 	int 	i;

// 	i = 0;
// 	while (is )
// }

static t_rgb *rgb_get(const char *srgb)
{
	const char	**trgb;
	t_rgb		*rgb;
	
	// if (!alpha_check(srgb))
	// {
	// 	printf("aaaaaaaa");
	// 	return (NULL);
	// }
	trgb = ft_split(srgb, ',');
	if (!trgb)
		return (NULL);
	if (map_size(trgb) > 4)
		return (NULL);
	rgb = malloc(sizeof(t_rgb *));
	if (!rgb)
	{
		free_map(trgb);
		return (NULL);
	}
	rgb->red = ft_atou(trgb[0]);
	rgb->green = ft_atou(trgb[1]);
	rgb->blue = ft_atou(trgb[2]);
	if (map_size(trgb) == 3)
		rgb->alpha = ft_atou(trgb[2]);
	free_map(trgb);
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
	return (1);
}

unsigned int rgb_convert(const char *srgb)
{
	t_rgb			*rgb;
	unsigned int 	value;

	if (!srgb)
		return (err_int("rgb entry is missing or invalid.\n", -1));
	rgb = rgb_get(srgb);
	// printf("%d %d %d\n", rgb->red, rgb->green, rgb->blue);
	if (!rgb)
		return (err_int("rgb entry is missing or invalid.\n", -1));
	if (!rgb_check(rgb))
	{
		free(rgb);
		return (err_int("rgb entry is missing or invalid.\n", -1));
	}
	rgb->alpha = 255; //enlever
	value = rgb->red << 24 | rgb->green << 16 | rgb->blue << 8 | rgb->alpha;
	
	printf("r: %d g:%d b:%d a:%d value : %x\n", rgb->red, rgb->green, rgb->blue, rgb->alpha, value);
	free(rgb);
	return (value);
}
