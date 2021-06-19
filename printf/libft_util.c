/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:12:51 by seopark           #+#    #+#             */
/*   Updated: 2021/06/19 15:00:17 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->cnt++;
}

int		is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int		calc_num(char c, int num)
{
	num = (num * 10) + (c - '0');
	return (num);
}

int		digit_len(long long num)
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
