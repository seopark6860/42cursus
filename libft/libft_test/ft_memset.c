#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int i;

	i = 0;
	while (len)
	{
		*((unsigned char *)b + i) = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
int main(){
	char arr1[] = "abcdddddd";
	char arr2[] = "abcdddddd";
	printf("%s\n", memset(arr1, 'c', 5*sizeof(char)));
	printf("%s\n", ft_memset(arr2, 'c', 5*sizeof(char)));
}
