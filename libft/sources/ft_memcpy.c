/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:13:05 by chhoflac          #+#    #+#             */
/*   Updated: 2024/11/24 17:13:07 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst2;
	const char	*src2;

	dst2 = dest;
	src2 = src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	dest = dst2;
	return (dest);
}
