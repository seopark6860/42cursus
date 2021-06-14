
#include "ft_printf.h"

//void	ft_recursive(char *hex_str, unsigned int num, int cnt, int upper)
void	ft_recursive(char *hex_str, unsigned long long num, int cnt, int upper)
{
//	hex_str[0] = '0';
//	hex_str[1] = 'x';
	hex_str[cnt--] = '\0';
	if (num == 0)
		hex_str[cnt] = '0';
	while (num > 0)
	{
		int mod = num % 16;
		if (mod < 10)
				hex_str[cnt--] = mod + '0';
		else
		{
			if (upper == 0)
				hex_str[cnt--] = mod + 87;
			else
				hex_str[cnt--] = mod + 55;
		}
		num /= 16;
	}
}

//char	*handle_hex(char copy,  unsigned int num)
char	*handle_hex(char copy,  unsigned long long num)
{
	unsigned long long	ncopy;
	char			*hex_str;
	int cnt;

	ncopy = num;
	cnt = 1;
	while (ncopy > 15)
	{
		ncopy /= 16;
		cnt++;
	}
/*
	if (!(hex_str = (char *)malloc(cnt + 3)))
		return (0);
	hex_str[0] = '0';
	hex_str[1] = 'x';
*/
	if (!(hex_str = (char *)malloc(cnt + 1)))
		return (0);
	if (copy == 'x')
//		ft_recursive(hex_str, num, cnt + 2, 0);
		ft_recursive(hex_str, num, cnt, 0);
	else
//		ft_recursive(hex_str, num, cnt + 2, 1);
		ft_recursive(hex_str, num, cnt, 0);
	return (hex_str);
}