#include "ft_printf.h"

void		handle_awidth(t_flags *flags, va_list ap)	// *플래그 만났을 때 width
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
	if (flags->precision < 0)		// precision 음수면 무시
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
	/* .뒤는 숫자 / 서식지정자 / * 이기 때문에 */
	while (is_spec(*copy) != 1)		// 서식지정자가 아니면 그전까지 읽어서 정밀도 값 계산
	{
		if (*copy == '*')
		{
			handle_aprecision(flags, ap);
			copy++;
			return (copy);
		}
		else	// 숫자이면 
			num = calc_num(*copy, num);
		copy++;
	}
	flags->precision = num;
	return (copy);
}


