#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	unsigned char uc;

	uc = (unsigned char)c;
	printf("c : %d\n", uc);
	if (('A' <= uc && uc <= 'Z') || ('a' <= uc && uc <= 'z'))
		return (1);
	else
		return (0);
}
int main()
{
	printf("%d\n", isalpha(-2));
	printf("%d\n", ft_isalpha(-2));
}
