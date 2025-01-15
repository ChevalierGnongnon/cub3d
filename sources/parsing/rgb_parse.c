/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:37:38 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/15 16:41:19 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	rgb_set(t_rgb *rgb, const char *srgb, int *i, int cnt)
{
	const char	*num;
	int 		value;
	int			j;
	
	j = (*i);
	if (cnt > 3)
		return (-1);
	while (ft_isdigit(srgb[(*i)]))
		(*i)++;
	num = ft_substr(srgb, j, (*i) - j);
	if (!num)
		return (-1);
	// printf("str : %s\n", num);
	value = ft_atoi(num);
	// printf("value : %d\n\n", value);
	if (cnt == 0)
		rgb->red = value;
	else if (cnt == 1)
		rgb->green = value;
	else if (cnt == 2)
		rgb->blue = value;
	else if (cnt == 3)
		rgb->alpha = value;
	free((void *) num);
	return (0);
}

static t_rgb	*rgb_get(const char *srgb)
{
	t_rgb	*rgb;
	int		i;
	int		cnt;
	
	i = 0;
	cnt = 0;
	rgb = ft_calloc(sizeof(t_rgb), 1);
	if (!rgb)
		return (NULL);
	rgb->red = -1;
	rgb->green = -1;
	rgb->blue = -1;
	rgb->alpha = 255;
	while (srgb[i])
	{
		if (srgb[i] == '-')
			return (NULL);
		if (ft_isdigit(srgb[i]))
		{
			if(rgb_set(rgb, srgb, &i, cnt) == -1)
				return (NULL);
			cnt++;
		}
		i++;
	}
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
	if (!rgb)
		return (err_int("rgb entry is missing or invalid.\n", -1));
	if (!rgb_check(rgb))
	{
		free(rgb);
		return (err_int("rgb entry is missing or invalid.\n", -1));
	}
	value = 0;
	printf("r : %d g : %d b: %d a: %d\n", rgb->green, rgb->red, rgb->blue, rgb->alpha);
	value += rgb->red << 24 | rgb->green << 16 | rgb->blue << 8 | 1;
	free(rgb);
	return (value);
}
