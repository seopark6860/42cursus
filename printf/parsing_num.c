/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:12:20 by seopark           #+#    #+#             */
/*   Updated: 2021/06/19 15:34:18 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_zero_num(t_flags *flags, char *str)
{
	if (flags->dot == 1 && flags->precision <= 0 && flags->width == 0)
	{
		free(str);
		return (0);
	}
	while (flags->width > 0 && flags->precision == 0)
	{
		ft_putchar(' ', flags);
		flags->width--;
		if (flags->width == 0)
		{
			free(str);
			return (0);
		}
	}
	return (1);
}

void	handle_int_width(t_flags *flags, char *str, int len, int negative)
{
	if (flags->width <= len)
	{
		flags->width = 0;
		flags->minus = 0;
		print_width(flags, 0);
		print_minus(flags, negative);
		print_str(flags, str);
	}
	else
	{
		flags->width -= len;
		print_int_width(flags, str, negative);
	}
}

int		handle_integer(t_flags *flags, char c, char *str, long long num)
{
	int	negative;

	if (!(str = printf_itoa(num)))
		return (-1);
	if (c == 'x' || c == 'X')
	{
		free(str);
		str = handle_hex(c, (unsigned long long)num);
	}
	negative = 0;
	if (num < 0)
	{
		negative = 1;
		flags->width--;
	}
	if (num == 0)
		if (handle_zero_num(flags, str) == 0)
			return (1);
	if (flags->dot == 0)
		handle_int_width(flags, str, printf_strlen(str), negative);
	else
		handle_int_prec(flags, str, printf_strlen(str), negative);
	free(str);
	return (1);
}

int		parsing_num(t_flags *flags, char c, va_list ap)
{
	long long			num;
	char				*str;
	unsigned long long	p;

	num = 0;
	str = "";
	p = -1;
	if (c == 'p')
	{
		p = (unsigned long long)va_arg(ap, void *);
		if (!(str = handle_hex('x', p)))
		{
			free(str);
			return (-1);
		}
		handle_pointer(flags, str, p);
		free(str);
		return (1);
	}
	else if (c == 'd' || c == 'i')
		num = va_arg(ap, int);
	else if (c == 'u' || c == 'x' || c == 'X')
		num = va_arg(ap, unsigned int);
	return (handle_integer(flags, c, str, num));
}
