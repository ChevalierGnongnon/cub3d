/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:09:30 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/09 10:22:47 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	while (line[end] && !is_whitespace(line[end]))
		end++;
	path = ft_substr(line, start, end - start);
	if (!path)
		return (NULL);
	return (path);
}
