/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:57:24 by seopark           #+#    #+#             */
/*   Updated: 2021/05/12 20:34:03 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[h] != 0)
	{
		while (haystack[h + n] == needle[n] && h + n < len)
		{
			n++;
			if (needle[n] == 0)
				return ((char *)&haystack[h]);
		}
		h++;
		n = 0;
	}
	return (0);
}
