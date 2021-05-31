#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n--)
	{
		if (*source == (unsigned char)c)
		{
			*dest = *source;
			dest++;
			return (dest);
		}
		*dest = *source;
		dest++;
		source++;
	}
	return (0);
}
int main()
{
	char arr[] = "abcdefghijklmnopqrstuvwxyz";
	char src[] = "abcdefghijklmnopqrstuvwxyz";
	char *ss = "string with\200inside !";

	char arr2[] = "abcdefghijklmnopqrstuvwxyz";
	char src2[] = "abcdefghijklmnopqrstuvwxyz";
	char *ss2 = "string with\200inside !";
	printf("200 : %d\n", 0600);
	printf("%s\n", memccpy(arr, ss, 0600, sizeof(src))); 
	printf("%s\n", ft_memccpy(arr2, ss2, 0600, sizeof(src2)));
	printf("\n%s\n", arr);
	printf("%s\n", arr2);
}
