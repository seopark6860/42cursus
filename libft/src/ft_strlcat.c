/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:24:18 by seopark           #+#    #+#             */
/*   Updated: 2021/05/18 12:18:18 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int s_len;
	unsigned int d_len;
	unsigned int res;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize <= d_len)
		res = s_len + dstsize;
	else
		res = d_len + s_len;
	if (dstsize > d_len)
	{
		i = 0;
		while (src[i] && (d_len < dstsize - 1))
		{
			dst[d_len] = src[i];
			d_len++;
			i++;
		}
		dst[d_len] = '\0';
	}
	return (res);
}
