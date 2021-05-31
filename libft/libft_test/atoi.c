#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int ft_atoi(const char *str)
{
	char	*s;
	long long	num;
	int		minus;

	s = (char *)str;
	while (isspace(*s))
		s++;
	minus = 1;
	if (*s == '-')
		minus = -1;
	if (*s == '-' || *s == '+')
		s++;
	num = 0;
	while (isdigit(*s))
	{
		if (num > 2147483647)
			return (-1);
		else if (num < -2147483648)
			return (0);
		else
			num = num * 10 + (*s - '0');
		s++;
	}
	return ((int)num * minus);
}
int main()
{
//	printf("%d\n", atoi("abcd200cdef"));	// 0
//	printf("%d\n", atoi("2020"));	// 2020
//	printf("%d\n", atoi("++abc20"));
//	printf("%d\n", atoi("-+200abcd"));	// 200
//	printf("%d\n", atoi("abcd32"));		// 0
//	printf("%d\n", atoi("\n\n33"));		// 33
//	printf("%d\n", atoi("0"));	// 0
	printf("%d\n", atoi("-2147483648"));
//	printf("%d\n", atoi("-12312314122312412"));
//	printf("%d\n", atoi("99999999999999999999999999"));
//	printf("%d\n", atoi("9223372036854775808"));
//	printf("%d\n", atoi("-99999999999999999999999999"));
//	printf("%d\n", atoi("24114353545"));
//	printf("%d\n", atoi("-085"));


//	printf("----------------\n");
//	printf("%d\n", ft_atoi("abcd200cdef"));
//	printf("%d\n", ft_atoi("2020"));
//	printf("%d\n", ft_atoi("++abc20"));
//	printf("%d\n", ft_atoi("-+200abcd"));
//	printf("%d\n", ft_atoi("abcd32"));
//	printf("%d\n", ft_atoi("\n\n33"));
//	printf("%d\n", ft_atoi("0"));
//	printf("%d\n", ft_atoi("11111111111111111111"));
//	printf("%d\n", ft_atoi("99999999999999999999999999"));
//	printf("%d\n", ft_atoi("-99999999999999999999999999"));
	printf("%d\n", ft_atoi("-2147483648"));
//	printf("%d\n", ft_atoi("9223372036854775808"));
}
