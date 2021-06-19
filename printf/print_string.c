/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:13:04 by seopark           #+#    #+#             */
/*   Updated: 2021/06/19 15:09:44 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_flags *flags, char *str)
{
	while (*str)
	{
		ft_putchar(*str, flags);
		str++;
	}
}

void	print_str_precision(t_flags *flags, char *str)
{
	if (flags->width >= flags->precision)
		flags->width -= flags->precision;
	else
		flags->width = 0;
	if (flags->minus == 1)
	{
		while (flags->precision-- > 0)
		{
			ft_putchar(*str, flags);
			str++;
		}
		print_width(flags, 0);
	}
	else
	{
		print_width(flags, 0);
		while (flags->precision-- > 0)
		{
			ft_putchar(*str, flags);
			str++;
		}
	}
}

void	print_str_width(t_flags *flags, char *str)
{
	if (flags->minus == 1)
	{
		print_str(flags, str);
		print_width(flags, 0);
	}
	else
	{
		print_width(flags, 1);
		print_str(flags, str);
	}
}

void	print_string(t_flags *flags, va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if ((len = printf_strlen(str)) == -1)
	{
		str = "(null)";
		len = 6;
	}
	if (flags->dot == 1)
	{
		if (flags->precision > len)
			flags->precision = len;
		print_str_precision(flags, str);
	}
	else
	{
		if (flags->width <= len)
			flags->width = 0;
		else
			flags->width -= len;
		print_str_width(flags, str);
	}
}
