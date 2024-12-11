/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:15:05 by chhoflac          #+#    #+#             */
/*   Updated: 2024/12/11 11:15:16 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

const char *dup_line(const char *line)
{
	char	*new;
	int		i;
	
	i = 0;
	new = malloc(ft_strlen(line));
	if (!new)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}