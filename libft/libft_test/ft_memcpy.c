#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*dest;
	unsigned char	*source;
	
	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dest == 0 && source == 0)
		return (dst);
	while (n--)
	{
		*(dest + i) = *(source + i);
		i++;
	}
	return (dst);
}

int main()
{
	char arr1[] = "abcdefghij";
//	char *arr1 = 0;
	char arr2[] = "abcdefghij";
	printf("%s\n", memcpy(arr1 + 4, arr1 + 2, 5));
//	for(int i=0; i<10; i++){
//		printf("arr1 : %c\n", arr1[i]);
//	}

	printf("%s\n", ft_memcpy(arr2 + 4, arr2 + 2, 5));
//	for(int i=0; i<10; i++){
//		printf("arr2 : %c\n", arr2[i]);
//	}
}

