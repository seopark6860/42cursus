/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:41:28 by seopark           #+#    #+#             */
/*   Updated: 2021/05/12 14:06:59 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;
	int i;

	len = ft_strlen(s);
	i = 0;
	while (len - i >= 0)
	{
		if (s[len - i] == (char)c)
		{
			return ((char *)(s + len - i));
		}
		i++;
	}
	return (0);
}
