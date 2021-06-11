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
/*
void	handle_integer(t_flags *flags, va_list ap)
{
	char	*nptr;
	int 	num;
	int 	len;

	num = va_arg(ap, int);
	nptr = ft_itoa(num);
	len = ft_strlen(nptr);

	if (flags->minus == 1)
	{
		while (len-- > 0)	// len만큼 숫자 출력하고
		{
			ft_putchar(*nptr);
			nptr--;
			flags->cnt++;
		}
		padding_integer(flags, nptr, len);	// 남은 공간 
		print_integer(flags, len);
	}
	else
	{
		while (len-- > 0)	// len만큼 숫자 출력하고
		{
			ft_putchar(*nptr);
			nptr--;
			flags->cnt++;
		}
		padding_integer(flags, nptr, len);	// 남은 공간
		print_integer(flags, len);
	}
	
}
*/
//void	handle_integer(t_flags)
//{
//	if ()
//}
/*
void	print_integer(t_flags *flags, int len)
{
	int print;

	if (flags->precision > len)
	{
		print = flags->precision - len;
		while (print-- > 0)
			ft_putchar('0');
	}
}
*/
/*
void	padding_integer(t_flags *flags, char *nptr, int len)		// 숫자출력하고 남은 공간 출력해줌 - width와 precision비교
{
	if (flags->width == 1 && flags->precision == 1)		// width, precision	둘다있으면	
	{
		if (flags->precision > flags->width)		// 총출력 precision
		{
			if (flags->precision > len)				// 숫자 출력하고 남은 공간 0으로 채움
				flags->precision -= len;
		}
		else		// 총출력 width
		{
			if (flags->precision > len)
			{
				flags->width = flags->width - flags->precision - len;
				flags->precision -= len;
			}
		}
	}
	// precision 있는지 확인
	handle_integer(flags);		// width, precision
}
*/
void	check_specifier(const char *copy, t_flags *flags, va_list ap)
{
	switch (*copy)
	{
		case 'c':
			print_char(flags, ap);
			break;
		case 's':
			print_string(flags, ap);
			break;
//		case 'd':
//			handle_integer(flags, ap);
//			break;	
		default:
			break;
	}
}

const char *check_flags(const char *copy, t_flags *flags, va_list ap)
{
	int result;

	result = flags->cnt;
	init_flags(flags, result);
	
	while (is_spec(*copy) == 0)		// 서식지정자 나오기 전까지 플래그 체크
	{
		if (*copy == '0')
			flags->zero = 1;
		if (*copy == '-')
			flags->minus = 1;
		if (*copy == '*')
			handle_awidth(flags, ap);
		if (*copy == '.')
		{
			copy = handle_dot(copy, flags, ap);
			break;
		}
		if (is_digit(*copy) && flags->star != 1)	// *없이 숫자 나오면 폭
		{
			flags->width = calc_num(*copy, flags->width);
		}
		copy++;
	}
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
		{
			ft_putchar(*copy, &flags);
		}
		else
		{
		//	init_flags(&flags);
			copy = check_flags(++copy, &flags, ap);
		}
		copy++;
	}
	return (flags.cnt);
}