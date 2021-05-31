/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:18:05 by seopark           #+#    #+#             */
/*   Updated: 2021/05/13 17:52:48 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_len(long long num)
{
	int cnt;

	cnt = 0;
	while (num)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_convert(int sign, int len, long long num)
{
	char	*res;

	if (sign)
		res = (char *)malloc(sizeof(char) * (len + 1));
	else
		res = (char *)malloc(sizeof(char) * (len + 2));
	if (!res)
		return (0);
	if (!sign)
	{
		len += 1;
		res[0] = '-';
	}
	res[len--] = '\0';
	while (num)
	{
		if (!sign && len == 0)
			break ;
		res[len--] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
/*
char	*f_strdup(char *s1)
{
	char	*arr;
	size_t	len;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	ft_memcpy(arr, s1, len + 1);
	free(s1);
	return (arr);
}
*/
char	*ft_itoa(int n)
{
	char		*arr;
	int			sign;
	long long	num;

	sign = 1;
	num = n;
	if (n < 0)
	{
		num *= -1;
		sign = 0;
	}
	if (n == 0)
	{
		if (!(arr = (char *)malloc(sizeof(char) * 2)))
			return (0);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	arr = ft_convert(sign, ft_len(num), num);
	if (!arr)
		return (0);
return (arr);	
//	return (ft_convert(sign, ft_len(num), num));
}
