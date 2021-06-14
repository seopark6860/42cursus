/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:18:05 by seopark           #+#    #+#             */
/*   Updated: 2021/06/13 17:19:19 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		res[len--] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}

char		*ft_itoa(long long n)
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
		if (!(arr = (char *)malloc(sizeof(char) * 2)))	/////vvvvv
			return (0);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	return (ft_convert(sign, digit_len(num), num));
}
