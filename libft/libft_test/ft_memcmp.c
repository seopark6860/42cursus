#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 > *str2)
		{
			printf("1 : %c %c\n", *str1, *str2);
			return (*str1 - *str2);
		}
		else if (*str1 < *str2)
		{
			printf("2 : %c %c\n", *str1, *str2);
			return (*str1 - *str2);
		}
		printf("3 : %c %c\n", *str1, *str2);
		str1++;
		str2++;
	}
	return (0);
}

int main()
{
//	char arr[] = "abcde";
//	char arr2[] = 0;
	
	printf("%d\n", memcmp("atoms\0\0\0\0", "atoms\0abc", 8));
	printf("%d\n", ft_memcmp("atoms\0\0\0\0", "atoms\0abc", 8));
}
