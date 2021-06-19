/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:12:46 by seopark           #+#    #+#             */
/*   Updated: 2021/06/19 15:09:15 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_pointer_zero(t_flags *flags)
{
	if (flags->dot == 0 && flags->precision <= 0 && flags->width == 0)
	{
		ft_putchar('0', flags);
		ft_putchar('x', flags);
		return (1);
	}
	ft_putchar('0', flags);
	ft_putchar('x', flags);
	while (flags->width > 0 && flags->precision == 0)
	{
		ft_putchar(' ', flags);
		flags->width--;
		if (flags->width == 0)
		{
			if (flags->width == 0)
			{
				return (0);
			}
		}
	}
	return (0);
}

void	handle_pointer_width(t_flags *flags, char *str, int len)
{
	if (flags->width <= len)
	{
		flags->width = 0;
		flags->minus = 0;
		print_pointer_width(flags, str);
	}
	else
	{
		flags->width -= len;
		print_pointer_width(flags, str);
	}
}

void	handle_pointer_prec(t_flags *flags, char *str, int len)
{
	if ((flags->precision > len) && (flags->width >= flags->precision))
	{
		flags->width -= flags->precision;
		flags->precision -= len;
		print_pointer_prec(flags, str);
	}
	else if ((flags->precision > len) && (flags->width < flags->precision))
	{
		flags->width = 0;
		flags->minus = 0;
		flags->precision -= len;
		print_pointer_prec(flags, str);
	}
	else if (flags->precision <= len)
	{
		flags->width -= len;
		print_pointer_width(flags, str);
	}
}

void	handle_pointer(t_flags *flags, char *str, unsigned long long p)
{
	int		len;
	char	*tmp;

	tmp = "";
	len = printf_strlen(str);
	flags->width -= 2;
	if (flags->precision == 0 && p == 0)
	{
		str = tmp;
		flags->width++;
	}
	if (flags->dot == 0)
		handle_pointer_width(flags, str, len);
	else
		handle_pointer_prec(flags, str, len);
}
