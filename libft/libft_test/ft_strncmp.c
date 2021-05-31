#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (1);
		else if (*(unsigned char *)s1 < *(unsigned char *)s2)
			return (-1);
		s1++;
		s2++;
	}
	return (0);
}

int main(){
//	printf("%d\n", strncmp("atoms\0\0\0\0", "atoms\0abc", 8));
//	printf("%d\n", ft_strncmp("atoms\0\0\0\0", "atoms\0abc", 8));
	printf("%d\n", strncmp("abcd\0abb", "abcddd", 8));
	printf("%d\n", ft_strncmp("abcd\0abb", "abcddd", 8));
	printf("%c\n", 0);
	printf("%d\n", 0);
	printf("%c\n", '\0');
	printf("%d\n", '\0');
}
