#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int					i;
	unsigned char		*dest;
	const unsigned char	*source;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst == 0 && source == 0)
		return (0);
	if (source < dest)
	{
		while (len--)
			*(dest + len) = *(source + len);
	}
	else {
		while (len--)
		{
			*dest = *source;
			dest++;
			source++;
		}
	}
	return (dst);
}

int main()
{
//	char arr1[] = "dddddddddd";
	char src1[] = "abcdefghij";
//	char arr2[] = "dddddddddd";
	char src2[] = "abcdefghij";
	
	printf("%s\n", memmove(src1 + 2, src1 + 4, 5));
	printf("%s\n", ft_memmove(src2 +2, src2 + 4, 5));
}
