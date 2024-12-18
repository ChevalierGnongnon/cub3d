/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:37:38 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/18 14:46:54 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int check_range(const char *rgb, int key)
{
	char	*value;
	int		num;
	int 	end;

	end = key;
	while (rgb[end] && ft_isdigit(rgb[end]))
		end++;
	if (end == key)
		return(0);
	value = ft_substr(rgb, key, end - key);
	if (!value)
		return (0);
	num = ft_atoi(value);
	free(value);
	if (num < 0 || num > 255)
		return (0);
	return (1);
}

int	rgb_check(const char *rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		printf("%c", rgb[i]);
		if (rgb[i] == ',')
		{
			if (rgb[i + 1] == ',')
				return (0);
		}
		else if (ft_isdigit(rgb[i]))
		{
			
			if (!check_range(rgb, i))
				return (0);
			while (ft_isdigit(rgb[i]))
				i++;
		}
		if (is_whitespace(rgb[i]) || rgb[i] != ','
			|| !ft_isdigit(rgb[i]) || rgb[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
