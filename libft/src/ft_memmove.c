/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:16:07 by seopark           #+#    #+#             */
/*   Updated: 2021/05/17 20:20:47 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int					i;
	unsigned char		*dest;
	const unsigned char	*source;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst == 0 && source == 0)
		return (dst);
	if (source < dest)
	{
		while (len--)
			*(dest + len) = *(source + len);
	}
	else
	{
		while (len--)
		{
			*dest = *source;
			dest++;
			source++;
		}
	}
	return (dst);
}
