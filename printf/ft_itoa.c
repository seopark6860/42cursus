/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:18:05 by seopark           #+#    #+#             */
/*   Updated: 2021/06/15 18:25:07 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert(int len, long long num)
{
	char	*res;


	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
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
	}
	if (n == 0)
	{
		if (!(arr = (char *)malloc(sizeof(char) * 2)))	/////vvvvv
			return (0);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	return (ft_convert(digit_len(num), num));
}
