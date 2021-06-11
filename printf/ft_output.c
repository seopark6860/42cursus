#include "ft_printf.h"

void	print_width(t_flags *flags)
{
	while (flags->width-- > 0)
	{
		ft_putchar(' ', flags);
	}
}

void	print_char(t_flags *flags, va_list ap)	// 문자 한개 출력
{
	flags->width--;				
	if (flags->minus == 1)		// -플래그이면 문자한개 먼저 출력하고 
	{
		ft_putchar(va_arg(ap, int), flags);
		print_width(flags);	// 공백 출력
	}
	else if (flags->width > 0)		// 폭이 1보다 크면 공백먼저 출력하고 
	{
		print_width(flags);
		ft_putchar(va_arg(ap, int), flags); // 문자출력
	}
	else
		ft_putchar(va_arg(ap, int), flags);
}