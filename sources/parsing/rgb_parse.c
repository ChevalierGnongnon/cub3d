/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:37:38 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/18 18:34:25 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// static int alpha_check(const char *line)
// {
// 	int i; 
	
// 	i = 0;
// 	while (line[i])
// 	{
// 		printf("'%c'\n", line[i]);
// 		if (!is_whitespace(line[i]) && !ft_isdigit(line[i])
// 			&& line[i] != '\n' && line[i] != ',')
// 			return (0);
// 		i++;
// 	}
// 	printf("aaaaaaaa");
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
	if (map_size(trgb) > 3)
		return (NULL);
	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
	{
		free_map(trgb);
		return (NULL);
	}
	rgb->red = (unsigned int)ft_atoi(trgb[0]);
	rgb->green = (unsigned int)ft_atoi(trgb[1]);
	rgb->blue = (unsigned int) ft_atoi(trgb[2]);
	if (map_size(trgb) == 3)
		rgb->alpha = ft_atoi(trgb[2]);
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
	if (rgb->alpha < 0 || rgb->alpha > 255)
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
	// printf("%d\n", rgb->red);
	// if (!rgb)
	// 	return (err_int("rgb entry is missing or invalid.\n", -1));
	// if (!rgb_check(rgb))
	// {
	// 	free(rgb);
	// 	return (err_int("rgb entry is missing or invalid.\n", -1));
	// }
	value = 0;
	value += rgb->red << 24 | rgb->green << 16 | rgb->blue << 8 | rgb->alpha;
	free(rgb);
	return (value);
}
