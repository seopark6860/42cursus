#include <string.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	int i;

	i = 0;
	while (n)
	{
		*((unsigned char *)s + i) = 0;
		i++;
		n--;
	}
}

int main(){
	char arr1[] = "abcddd";
	char arr2[] = "abcddd";

//	bzero(arr1, 4*sizeof(char));
	bzero(arr1, 3);
	printf("%s\n", arr1);
//	ft_bzero(arr2, 4*sizeof(char));
	ft_bzero(arr2, 3);
	printf("%s\n", arr2);
}
