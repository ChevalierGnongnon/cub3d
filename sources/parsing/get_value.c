/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:09:30 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/09 10:46:26 by chhoflac         ###   ########.fr       */
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

const char	*get_value(char *line, size_t start)
{
	const char	*path;
	int			end;

	while (line[start] && !is_whitespace(line[start]))
		start++;
	while (line[start] && is_whitespace(line[start]))
		start++;
	if (start == ft_strlen(line))
		return (NULL);
	end = start;
	if (check_line(line, start))
	{
		while (line[end] && !is_whitespace(line[end]))
			end++;
		path = ft_substr(line, start, end - start);
		if (!path)
			return (NULL);
		return (path);
	}
	return (NULL);
}
