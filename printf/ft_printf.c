/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:12:34 by seopark           #+#    #+#             */
/*   Updated: 2021/06/19 17:26:12 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_flags(t_flags *flags, int result)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->precision = -1;
	flags->star = 0;
	flags->cnt = result;
}

const char	*calc_width(t_flags *flags, const char *copy)
{
	while (is_digit(*copy))
	{
		flags->width = calc_num(*copy, flags->width);
		copy++;
	}
	copy--;
	return (copy);
}

int			check_specifier(const char *copy, t_flags *flags, va_list ap)
{
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->dot == 1 && flags->precision < 0)
		flags->dot = 0;
	if (*copy == 'c')
		print_char(flags, ap);
	else if (*copy == 's')
		print_string(flags, ap);
	else if (*copy == 'd' || *copy == 'i' || *copy == 'u' ||
	*copy == 'x' || *copy == 'X')
	{
		if (flags->dot == 1 && flags->zero == 1)
			flags->zero = 0;
		return (parsing_num(flags, *copy, ap));
	}
	else if (*copy == 'p')
		return (parsing_num(flags, *copy, ap));
	else if (*copy == '%')
		print_percent(flags);
	else
		return (-2);
	return (1);
}

const char	*check_flags(const char *c, t_flags *flags, int res, va_list ap)
{
	int		tmp;

	init_flags(flags, res);
	while (*c == '-' || *c == '0' || *c == '*' || *c == '.' || is_digit(*c))
	{
		if (*c == '-')
			flags->minus = 1;
		else if (*c == '0')
			flags->zero = 1;
		else if (*c == '*')
			handle_awidth(flags, ap);
		else if (*c == '.')
		{
			c = handle_dot(c, flags, ap);
			break ;
		}
		else if (is_digit(*c) && flags->star != 1)
			c = calc_width(flags, c);
		c++;
	}
	if ((tmp = check_specifier(c, flags, ap)) == -1)
		return (0);
	else if (tmp == -2)
		return (--c);
	return (c);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_flags		flags;
	const char	*copy;
	int			res;

	va_start(ap, format);
	init_flags(&flags, 0);
	copy = format;
	while (*copy != '\0')
	{
		if ((*copy != '%'))
			ft_putchar(*copy, &flags);
		else
		{
			res = flags.cnt;
			copy = check_flags(++copy, &flags, res, ap);
			if (copy == 0)
				return (-1);
		}
		copy++;
	}
	return (flags.cnt);
}
