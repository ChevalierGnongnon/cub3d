/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:15:40 by chhoflac          #+#    #+#             */
/*   Updated: 2024/11/24 17:15:43 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (lit[0] == '\0')
		return ((char *)big);
	else if (ft_strlen(big) < ft_strlen(lit))
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (lit[j] && (big[i + j] == lit[j]) && (i + j < len))
			j++;
		if (lit[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
