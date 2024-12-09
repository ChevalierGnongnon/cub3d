/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:16:05 by chhoflac          #+#    #+#             */
/*   Updated: 2024/11/24 17:16:07 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) <= start)
		return (sub = ft_calloc(1, 1));
	else if (len > ft_strlen(s) - start)
		sub = ft_calloc(ft_strlen(s) - start + 1, 1);
	else if (ft_strlen(s) > len)
		sub = ft_calloc(len + 1, 1);
	else
		sub = ft_calloc(ft_strlen(s) + 1, 1);
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
