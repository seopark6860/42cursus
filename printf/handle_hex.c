/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:12:43 by seopark           #+#    #+#             */
/*   Updated: 2021/06/19 15:21:07 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_convert(int len, long long num)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len--] = '\0';
	while (num)
	{
		res[len--] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}

char	*printf_itoa(long long n)
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
		if (!(arr = (char *)malloc(sizeof(char) * 2)))
			return (0);
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	return (printf_convert(digit_len(num), num));
}

void	ft_recursive(char *hex_str, unsigned long long num, int cnt, int upper)
{
	int mod;

	mod = 0;
	hex_str[cnt--] = '\0';
	if (num == 0)
		hex_str[cnt] = '0';
	while (num > 0)
	{
		mod = num % 16;
		if (mod < 10)
			hex_str[cnt--] = mod + '0';
		else
		{
			if (upper == 0)
				hex_str[cnt--] = mod + 87;
			else
				hex_str[cnt--] = mod + 55;
		}
		num /= 16;
	}
}

char	*handle_hex(char copy, unsigned long long num)
{
	int					cnt;
	unsigned long long	ncopy;
	char				*hex_str;

	ncopy = num;
	cnt = 1;
	while (ncopy > 15)
	{
		ncopy /= 16;
		cnt++;
	}
	if (!(hex_str = (char *)malloc(cnt + 1)))
		return (0);
	if (copy == 'x')
		ft_recursive(hex_str, num, cnt, 0);
	if (copy == 'X')
		ft_recursive(hex_str, num, cnt, 1);
	return (hex_str);
}
