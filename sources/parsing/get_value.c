/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:09:30 by chhoflac          #+#    #+#             */
/*   Updated: 2025/01/30 17:01:08 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_line(char *line, int key)
{
	size_t	i;

	i = key;
	while (line[i] && !is_whitespace(line[i]))
		i++;
	if (i == ft_strlen(line))
		return (1);
	while (line[i])
	{
		if (!is_whitespace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static const char	*get_wall_texture(char *line, int start, int end)
{
	const char	*path;

	while (line[end] && !is_whitespace(line[end]))
		end++;
	path = ft_substr(line, start, end - start);
	if (!path)
		return (NULL);
	return (path);
}

static const char	*get_rgb(char *line, int start, int end)
{
	const char	*rgb;

	while (line[end])
		end++;
	rgb = ft_substr(line, start, end - start);
	if (!rgb)
		return (NULL);
	return (rgb);
}

const char	*get_value(char *line, char *key, size_t start, int *count)
{
	int	end;

	(*count)++;
	while (line[start] && !is_whitespace(line[start]))
		start++;
	while (line[start] && is_whitespace(line[start]))
		start++;
	if (start == ft_strlen(line))
		return (NULL);
	end = start;
	if (!ft_strcmp(key, "C ") || !ft_strcmp(key, "F ")
		|| !ft_strcmp(key, "C\t") || !ft_strcmp(key, "F\t"))
		return (get_rgb(line, start, end));
	if (!check_line(line, start))
		return (NULL);
	if (ft_strcmp(key, "C ") || ft_strcmp(key, "F ")
		|| !ft_strcmp(key, "C\t") || !ft_strcmp(key, "F\t"))
		return (get_wall_texture(line, start, end));
	return (NULL);
}
