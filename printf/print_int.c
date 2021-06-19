/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:12:58 by seopark           #+#    #+#             */
/*   Updated: 2021/06/19 14:58:35 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int_prec(t_flags *flags, char *str, int negative)
{
	if (flags->minus == 1)
	{
		print_minus(flags, negative);
		while (flags->precision-- > 0)
			ft_putchar('0', flags);
		print_str(flags, str);
		print_width(flags, 0);
	}
	else
	{
		print_width(flags, 1);
		print_minus(flags, negative);
		while (flags->precision-- > 0)
			ft_putchar('0', flags);
		print_str(flags, str);
	}
}

void	print_int_width(t_flags *flags, char *str, int negative)
{
	if (flags->minus == 1)
	{
		print_minus(flags, negative);
		print_str(flags, str);
		print_width(flags, 0);
	}
	else
	{
		if (negative == 1 && flags->zero == 0)
		{
			print_width(flags, 1);
			print_minus(flags, negative);
			print_str(flags, str);
		}
		else
		{
			print_minus(flags, negative);
			print_width(flags, 1);
			print_str(flags, str);
		}
	}
}

void	handle_int_prec(t_flags *flags, char *str, int len, int negative)
{
	if ((flags->precision) > len && (flags->width >= flags->precision))
	{
		flags->width -= flags->precision;
		flags->precision -= len;
		print_int_prec(flags, str, negative);
	}
	else if ((flags->precision > len) && (flags->width < flags->precision))
	{
		flags->width = 0;
		flags->minus = 0;
		flags->precision -= len;
		print_int_prec(flags, str, negative);
	}
	else if (flags->precision <= len)
	{
		flags->width -= len;
		print_int_width(flags, str, negative);
	}
}
