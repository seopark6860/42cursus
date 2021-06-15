#include "ft_printf.h"
#include <stdio.h>

void	init_flags(t_flags *flags, int result)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->precision = -1;
	flags->star = 0;
	flags->cnt = result;
}

int	calc_num(char c, int num)
{
	num = (num * 10) + (c - '0');
	return (num);
}

void	handle_int_prec(t_flags *flags, char *str, int len, int negative)
{
	if (flags->precision > len)					// precision-len만큼 0으로 채움
	{		
		if (flags->width >= flags->precision)	// w-p공백, p출력, len출력
		{
			flags->width -= flags->precision;
			flags->precision -= len;			// precision - len만큼 0출력
			if (flags->minus == 1)
			{
				print_minus(flags, negative);
				while (flags->precision-- > 0)		// precision 0 출력
					ft_putchar('0', flags);
				print_str(flags, str);				// len 출력
				print_width(flags, 0);		// width-precision 공백출력
			}
			else
			{
				print_width(flags, 1);		// width-precision 공백출력
				print_minus(flags, negative);
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
				print_minus(flags, negative);
				print_str(flags, str);
				while (flags->precision-- > 0)	// precision 0 출력
					ft_putchar('0', flags);
			}
			else
			{
				print_minus(flags, negative);
				while (flags->precision-- > 0)	// precision 0 출력
					ft_putchar('0', flags);
				print_str(flags, str);
			}	
		}	 
	}
	else		// precision 무시
	{
		flags->width -= len;
		print_int_width(flags, str, negative);
	}
}

void	handle_int_width(t_flags *flags, char *str, int len, int negative)	// p무시하고 출력
{
	if (flags->width <= len)		// width 무시 -> minus 무시
	{
		flags->width = 0;
		flags->minus = 0;
		if (flags->minus == 1)
		{
			print_minus(flags, negative);
			print_str(flags, str);
			print_width(flags, 0);
		}
		else
		{
			print_width(flags, 0);
			print_minus(flags, negative);
			print_str(flags, str);
		}
	}
	else		// width-len 공백출력
	{
		flags->width -= len;
		print_int_width(flags, str, negative);
	}
}

int	handle_zero_num(t_flags *flags, char *str)
{
	
	if (flags->dot == 1 && flags->precision <= 0 && flags->width == 0)	// 아무것도 출력안함
	{	
		free(str);
		return (0);
	}
	while (flags->width > 0 && flags->precision == 0)	// precision == 0 <=0 아님vvv
	{
		ft_putchar(' ', flags);
		flags->width--;
		if (flags->width == 0)
		{
			free(str);
			return (0);
		}
	}
	return (1);
}

void	handle_integer(t_flags *flags, char c, char *str, long long num)
{
	int len;
	int	negative;

	str = ft_itoa(num);
	if (c == 'x' || c == 'X')
	{
		free(str);
		str = handle_hex(c, (unsigned long long)num);
	}
	len = ft_strlen(str);
	negative = 0;
	if (num < 0)
	{
		negative = 1;
		flags->width--;		// width는 -부호 한공간으로 vvvvvvv
	}
	if (num == 0)
	{
		if (handle_zero_num(flags, str) == 0)
			return ;
	}
	if (flags->dot == 0)	// 정밀도 없을 때
		handle_int_width(flags, str, len, negative);
	else		// 정밀도 있을 때
		handle_int_prec(flags, str, len, negative);
	free(str);
}

void	pre_handle_integer(t_flags *flags, char c, va_list ap)
{
	long long			num;
	char 				*str;
	unsigned long long	 p;

	p = -1;
	num = 0;
	str = "";
	if (c == 'p')
	{
		p = (unsigned long long)va_arg(ap, void *);	
		str = handle_hex('x', p);
//		print_pointer(flags, str, p);
		print_pointer(flags, str);
		free(str);
		return ;
	}
	else if (c == 'd' || c == 'i')
		num = va_arg(ap, int);
	else if (c == 'u' || c == 'x' || c == 'X')
		num = va_arg(ap, unsigned int);
	handle_integer(flags, c, str, num);
}

void	check_specifier(const char *copy, t_flags *flags, va_list ap)
{
	if (*copy == 'c')
		print_char(flags, ap);
	else if (*copy == 's')
		print_string(flags, ap);
	else if (*copy == 'd' || *copy == 'i')
		pre_handle_integer(flags, *copy, ap);
	else if (*copy == 'u' || *copy == 'x' || *copy == 'X')
		pre_handle_integer(flags, *copy, ap);
	else if (*copy == 'p')
		pre_handle_integer(flags, *copy, ap);
	else if (*copy == '%')
	;
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

const char *check_flags(const char *copy, t_flags *flags, va_list ap)
{
	int result;

	result = flags->cnt;
	init_flags(flags, result);	
//	while (is_spec(*copy) == 0)		// 서식지정자 나오기 전까지 플래그 체크
	while (is_spec(*copy) == 0)
	{
		if (*copy == '-')
			flags->minus = 1;
		else if (*copy == '0')	
			flags->zero = 1;
		else if (*copy == '*')
			handle_awidth(flags, ap);
		else if (*copy == '.')
		{
			copy = handle_dot(copy, flags, ap);
			break;
		}
		else if (is_digit(*copy) && flags->star != 1)	// *없이 숫자 나오면 폭
			copy = calc_width(flags, copy);
		copy++;
	}
	if ((flags->minus == 1 && flags->zero == 1) || (flags->dot == 1 && flags->zero == 1))	// 0 플래그 -, .같이 쓰이면 무시
		flags->zero = 0;
	if (flags->dot == 1 && flags->precision < 0)
		flags->dot = 0;
	check_specifier(copy, flags, ap);		// 서식지정자 만나면 어떤 서식지정자인지 체크하는 함수로
	return (copy);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_flags	flags;
	const char	*copy;

	va_start(ap, format);
	flags.cnt = 0;
	init_flags(&flags, 0);
	copy = format;
	while (*copy != '\0')
	{
		if ((*copy != '%'))
			ft_putchar(*copy, &flags);
		else
			copy = check_flags(++copy, &flags, ap);
		copy++;
	}
	return (flags.cnt);
}