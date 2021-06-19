/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:12:30 by seopark           #+#    #+#             */
/*   Updated: 2021/06/19 14:34:50 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_flags *flags, va_list ap)
{
	flags->width--;
	if (flags->minus == 1)
	{
		ft_putchar(va_arg(ap, int), flags);
		print_width(flags, 0);
	}
	else if (flags->width > 0)
	{
		print_width(flags, 0);
		ft_putchar(va_arg(ap, int), flags);
	}
	else
		ft_putchar(va_arg(ap, int), flags);
}

void	print_width(t_flags *flags, int apply_zero)
{
	if (apply_zero == 1 && flags->zero == 1)
	{
		while (flags->width-- > 0)
			ft_putchar('0', flags);
		return ;
	}
	while (flags->width-- > 0)
	{
		ft_putchar(' ', flags);
	}
}

void	print_minus(t_flags *flags, int negative)
{
	if (negative == 1)
	{
		ft_putchar('-', flags);
		return ;
	}
}

void	print_percent(t_flags *flags)
{
	flags->width--;
	if (flags->minus == 1)
	{
		ft_putchar('%', flags);
		print_width(flags, 1);
	}
	else if (flags->width > 0)
	{
		print_width(flags, 1);
		ft_putchar('%', flags);
	}
	else
		ft_putchar('%', flags);
}
