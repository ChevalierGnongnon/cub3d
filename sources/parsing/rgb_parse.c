/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:37:38 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/06 13:57:35 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	rgb_set(t_rgb *rgb, const char *srgb, int *i, int cnt)
{
	const char	*num;
	int 		value;
	int			j;
	
	j = (*i);
	if (cnt > 2)
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
	rgb->red = 0;
	rgb->green = 0;
	rgb->blue= 0;
	while (srgb[i])
	{
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
	return (1);
}

unsigned int rgb_convert(const char *srgb)
{
	t_rgb			*rgb;
	unsigned int 	value;

	rgb = rgb_get(srgb);
	if (!rgb_check(rgb))
	{
		free(rgb);
		return (-1);
	}
	value = 0;
	value += rgb->red << 24 | rgb->green << 16 | rgb->blue << 8 | 1;
	printf("0x%X\n", value);
	free(rgb);
	return (value);
}
