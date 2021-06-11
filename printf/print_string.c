#include "ft_printf.h"

void	print_str_precision(t_flags *flags, char *str)
{
	if (flags->width >= flags->precision)
		flags->width -= flags->precision;
	else
		flags->width = 0;
	if (flags->minus == 1)
	{
		while (flags->precision-- > 0)		// 문자 출력
		{
			ft_putchar(*str, flags);
			str++;
		}
		print_width(flags);
	}
	else
	{
		print_width(flags);
		while (flags->precision-- > 0)		// 문자 출력
		{
			ft_putchar(*str, flags);
			str++;
		}
	}
}

void	print_str_width(t_flags *flags, char *str)		// width, 출력할 문자 수 정해주기
{
	if (flags->minus == 1)
	{
		while (*str)
		{
			ft_putchar(*str, flags);
			str++;
		}
		print_width(flags);
	}
	else
	{
		print_width(flags);
		while (*str)
		{
			ft_putchar(*str, flags);
			str++;
		}
	}
}
void	print_string(t_flags *flags, va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if ((len = ft_strlen(str)) == -1)
	{
		str = "(null)";
		len = 6;
	}
	if (flags->dot == 1)				// 정밀도 있을 때
	{
		if (flags->precision > len || flags->precision == -1)			// len과 비교
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