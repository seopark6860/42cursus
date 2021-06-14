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
		print_width(flags, 0);
	}
	else
	{
		print_width(flags, 0);
		while (flags->precision-- > 0)		// 문자 출력
		{
			ft_putchar(*str, flags);
			str++;
		}
	}
}

//void	print_str_width(t_flags *flags, char *str)	// width, 출력할 문자 수 정해주기
void	print_str_width(t_flags *flags, char *str)
{
	if (flags->minus == 1)
	{
		while (*str)
		{
			ft_putchar(*str, flags);
			str++;
		}
		print_width(flags, 0);
	}
	else
	{
		print_width(flags, 0);
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
		if (flags->precision > len || flags->precision == -1)	// len과 비교
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

void	print_int_width(t_flags *flags, char *str, int negative)	// width, 출력할 문자 수 정해주기
{
	// width-len 공백 또는 0 출력
	if (flags->minus == 1)
	{
		// 없어도 될듯..?
		if (negative == 1)
		{
			ft_putchar('-', flags);
			str++;
		}
		while (*str)			
		{
			ft_putchar(*str, flags);
			str++;
		}
		print_width(flags, 0);		// 0, - 플래그 같이 못씀
	}
	else
	{
		//	음수이고 0 플래그 없으면 음수 그대로 출력. 0플래그 있으면 -출력후 숫자 출력
		if (negative == 1 && flags->zero == 0)
		{
			print_width(flags, 1);
			while (*str)
			{	
				ft_putchar(*str, flags);
				str++;
			}
		}
		else
		{
			if (negative == 1)
			{
				ft_putchar('-', flags);
				str++;
			}
			print_width(flags, 1);
			while (*str)
			{
				ft_putchar(*str, flags);
				str++;
			}
		}
		
	}
}