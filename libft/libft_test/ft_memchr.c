#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int i;

	i = 0;
	while (n--)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}

int main()
{
	char arr[] = "abcdefghij";
	char arr2[] = "abcdefghij";

	printf("%s\n", memchr(arr, 99, 10));
	printf("%s\n", ft_memchr(arr2, 99, 10));
}
