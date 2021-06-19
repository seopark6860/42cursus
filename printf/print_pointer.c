/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:13:01 by seopark           #+#    #+#             */
/*   Updated: 2021/06/19 15:29:47 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer_width(t_flags *flags, char *str)
{
	if (flags->minus == 1)
	{
		ft_putchar('0', flags);
		ft_putchar('x', flags);
		print_str(flags, str);
		print_width(flags, 0);
	}
	else
	{
		print_width(flags, 1);
		ft_putchar('0', flags);
		ft_putchar('x', flags);
		print_str(flags, str);
	}
}

void	print_pointer_prec(t_flags *flags, char *str)
{
	if (flags->minus == 1)
	{
		ft_putchar('0', flags);
		ft_putchar('x', flags);
		print_str(flags, str);
		print_width(flags, 0);
	}
	else
	{
		print_width(flags, 1);
		ft_putchar('0', flags);
		ft_putchar('x', flags);
		print_str(flags, str);
	}
}
