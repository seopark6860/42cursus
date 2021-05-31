#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (48 <= (unsigned char)c  && (unsigned char)c <= 57)
		return (1); 
	else
		return (0);
}
#include <limits.h>
int main()
{
	printf("%d\n", isdigit(304));
	printf("%d\n", ft_isdigit(304));

	printf("%c\n", (unsigned char)(50));
}

