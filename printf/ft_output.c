#include "ft_printf.h"

void	print_width(t_flags *flags, int apply_zero)
{
	if (apply_zero == 1 && flags->zero == 1) 	// apply_zero == 1이면 공백을 0으로 채움. c,s는 flag->zero=1이더라도 apply_zero=0으로 들어옴
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
	//	str++;
		return ;
	}
//	else if (pointer == 1)
//	{
//		ft_putchar('0', flags);
//		ft_putchar('x', flags);
//	}
}

void	print_char(t_flags *flags, va_list ap)	// 문자 한개 출력
{
	flags->width--;				
	if (flags->minus == 1)		// -플래그이면 문자한개 먼저 출력하고 
	{
		ft_putchar(va_arg(ap, int), flags);
		print_width(flags, 0);	// 공백 출력
	}
	else if (flags->width > 0)		// 폭이 1보다 크면 공백먼저 출력하고 
	{
		print_width(flags, 0);
		ft_putchar(va_arg(ap, int), flags); // 문자출력
	}
	else
		ft_putchar(va_arg(ap, int), flags);
}