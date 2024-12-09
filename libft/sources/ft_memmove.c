/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:10:46 by chhoflac          #+#    #+#             */
/*   Updated: 2024/09/24 14:25:44 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d2;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	d2 = (unsigned char *) dest;
	s2 = (unsigned char *) src;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		if (d2 > s2)
			d2[n - i - 1] = s2[n - i - 1];
		else
			d2[i] = s2[i];
		i++;
	}
	dest = d2;
	return (dest);
}
