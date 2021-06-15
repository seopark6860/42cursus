#include "ft_printf.h"


#include <stdio.h>


void	handle_int_prec2(t_flags *flags, char *str, int len, int negative)
{
	if (flags->precision > len)	// precision-len만큼 0으로 채움
	{		
		if (flags->width >= flags->precision)	// w-p공백, p출력, len출력
		{
			flags->width -= flags->precision;
			flags->precision -= len;		// precision - len만큼 0출력
			if (flags->minus == 1)
			{
				ft_putchar('0', flags);
				ft_putchar('x', flags);
	//			flags->width -= 2;
				while (flags->precision-- > 0)		// precision 0 출력
					ft_putchar('0', flags);
				print_str(flags, str);			// len 출력
				print_width(flags, 0);		// width-precision 공백출력
			}
			else
			{
				print_width(flags, 1);		// width-precision 공백출력
				ft_putchar('0', flags);
				ft_putchar('x', flags);
	//			flags->width -= 2;
				while (flags->precision-- > 0)	// precision 0 출력
					ft_putchar('0', flags);
				print_str(flags, str);	// len 출력
			}
		}
		else		// width 무시 -> minus무시
		{
			flags->width = 0;
			flags->minus = 0;
			flags->precision -= len;
			if (flags->minus == 1)
			{
				ft_putchar('0', flags);
				ft_putchar('x', flags);
	//			flags->width -= 2;
				print_str(flags, str);
				while (flags->precision-- > 0)	// precision 0 출력
					ft_putchar('0', flags);
			}
			else
			{
				ft_putchar('0', flags);
				ft_putchar('x', flags);
	//			flags->width -= 2;
				while (flags->precision-- > 0)	// precision 0 출력
					ft_putchar('0', flags);
				print_str(flags, str);
			}	
		}	 
	}
	else		// precision 무시
	{
		flags->width -= len;
		print_int_width2(flags, str, negative);
	}
}
void	print_int_width2(t_flags *flags, char *str, int negative)	// width, 출력할 문자 수 정해주기
{
	// width-len 공백 또는 0 출력
	if (flags->minus == 1)
	{
		// 없어도 될듯..?
		if (negative == 1)
		{
			ft_putchar('0', flags);
			ft_putchar('x', flags);
	//		flags->width -= 2;
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
	//		flags->width -= 2;
			print_width(flags, 1);
			ft_putchar('0', flags);
			ft_putchar('x', flags);
			print_str(flags, str);
		}
		else
		{
			if (negative == 1)
			{
				ft_putchar('0', flags);
				ft_putchar('x', flags);
	//			flags->width -= 2;
			//	str++;
			}
			print_width(flags, 1);
			print_str(flags, str);
		}
		
	}
}
void	print_str_width2(t_flags *flags, char *str)
{
	if (flags->minus == 1)
	{
		ft_putchar('0', flags);
		ft_putchar('x', flags);
	//	flags->width -= 2;
		print_str(flags, str);
		print_width(flags, 0);
	}
	else
	{
		ft_putchar('0', flags);
		ft_putchar('x', flags);
	//	flags->width -= 2;
		print_width(flags, 0);	
		print_str(flags, str);
	}
}

void	handle_int_width2(t_flags *flags, char *str, int len, int negative)	// p무시하고 출력
{
	if (flags->width <= len)		// width 무시 -> minus 무시
	{
		flags->width = 0;
		flags->minus = 0;
		print_str_width2(flags, str);
	}
	else		// width-len 공백출력
	{
		flags->width -= len;
		print_int_width2(flags, str, negative);
	}
}
int	handle_zero_num2(t_flags *flags)
{
	if (flags->dot == 0 && flags->precision <= 0 && flags->width == 0)	// 아무것도 출력안함
	{	
		ft_putchar('0', flags);
		ft_putchar('x', flags);
	//	ft_putchar('0', flags);
	//	return (0);
		return (1);
	}
	ft_putchar('0', flags);
	ft_putchar('x', flags);
	while (flags->width > 0 && flags->precision == 0)	// precision == 0 <=0 아님vvv
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
//void	print_pointer(t_flags *flags, char *str, unsigned long long	 p)
void	print_pointer(t_flags *flags, char *str)
{
	int len;
	
	len = ft_strlen(str);
	flags->width -= 2;
//	if (p == 0)
//	{
	//	if (handle_zero_num2(flags) == 0)
	//		return ;
//		if (handle_zero_num2(flags) == 1)
//		{
//			ft_putchar('0', flags);
//			return ;
//		}
//	}
	if (flags->dot == 0)		// 정밀도 없을 때
		handle_int_width2(flags, str, len, 1);
	else
		handle_int_prec2(flags, str, len, 1);

}
