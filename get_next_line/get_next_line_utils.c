/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:33:41 by seopark           #+#    #+#             */
/*   Updated: 2021/05/29 15:20:44 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strdup(const char *s1)
{
	char	*arr;
	size_t	len;

	len = gnl_strlen(s1);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	gnl_memmove(arr, s1, len + 1);
	return (arr);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	len;

	len = gnl_strlen(src);
	if (dstsize)
	{
		idx = 0;
		while (idx < dstsize - 1 && src[idx] != '\0')
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (len);
}

void	*gnl_memmove(void *dst, const void *src, size_t len)
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

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	arr = (char *)malloc(s1_len + s2_len + 1);
	if (!arr)
		return (0);
	gnl_memmove(arr, s1, s1_len);
	gnl_memmove(arr + s1_len, s2, s2_len + 1);
	return (arr);
}
