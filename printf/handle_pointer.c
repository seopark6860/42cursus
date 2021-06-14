#include "ft_printf.h"

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
/*
void	handle_pointer(t_flags, *flags, char *str, un va_list ap)
{
	int len;
	
	len = ft_strlen(str);
	if ()
}
*/