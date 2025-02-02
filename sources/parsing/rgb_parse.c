/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:37:38 by chhoflac          #+#    #+#             */
/*   Updated: 2025/02/02 14:50:07 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	value_checker(const char **trgb)
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

static t_rgb	*rgb_get(const char *srgb)
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

static int	check_end(const char *srgb)
{
	int i;

	i = ft_strlen(srgb);
	printf("%d\n", i);
	while (is_whitespace(srgb[i]) && srgb[i] == '\0')
	{
		printf("'%c'\n", srgb[i]);
		i--;
	}
	printf("%d\n", i);
	if (srgb[i] ==',')
		return (0);
	return (1);
	
}

static int	transform_into_value(const char *srgb, int *checker)
{
	t_rgb	*rgb;
	int		value;
	
	value = 0;
	rgb = rgb_get(srgb);
	if (!check_end(srgb))
	{
		(*checker) = -1;
		return (0);
	}
	if (!rgb)
	{
		(*checker) = -1;
		return (0);
	}
	if (!rgb_check(rgb))
	{
		free(rgb);
		(*checker) = -1;
		return (0);
	}
	value += rgb->red << 24 | rgb->green << 16 | rgb->blue << 8 | rgb->alpha;
	free(rgb);
	// printf("%x\n", value);
	return (value);
}

unsigned int	rgb_convert(const char *srgb, int *checker)
{
	if (!srgb)
	{
		(*checker) = -1;
		return (0);
	}
	if (rgb_checker(srgb))
		return (transform_into_value(srgb, checker));
	(*checker) = -1;
	return (0);
}
