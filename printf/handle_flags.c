/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:12:40 by seopark           #+#    #+#             */
/*   Updated: 2021/06/19 15:03:48 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_awidth(t_flags *flags, va_list ap)
{
	flags->star = 1;
	flags->width = va_arg(ap, int);
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->minus = 1;
	}
}

void		handle_aprecision(t_flags *flags, va_list ap)
{
	flags->star = 1;
	flags->precision = va_arg(ap, int);
	if (flags->precision < 0)
	{
		flags->precision = -1;
		flags->dot = 0;
	}
}

const char	*handle_dot(const char *copy, t_flags *flags, va_list ap)
{
	int num;

	copy++;
	flags->dot = 1;
	num = 0;
	while (*copy != 'c' && *copy != 's' && *copy != 'p' && *copy != 'd' &&
		*copy != 'i' && *copy != 'u' && *copy != 'x' &&
			*copy != 'X' && *copy != '%')
	{
		if (*copy == '*')
		{
			handle_aprecision(flags, ap);
			copy++;
			return (copy);
		}
		else
			num = calc_num(*copy, num);
		copy++;
	}
	flags->precision = num;
	return (copy);
}
