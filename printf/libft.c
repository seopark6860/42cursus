#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->cnt++;
}

int is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	is_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || 
	c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	digit_len(long long num)
{
	int cnt;

	cnt = 0;
	while (num)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}
