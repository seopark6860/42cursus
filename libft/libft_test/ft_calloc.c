#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	printf("size : %lu\n", sizeof(size));

	arr = malloc(size * count);
	if (!arr)
		return (0);
	memset(arr, 0, count * size);
	return (arr);
}
int main()
{
	int count = 42 * 3;
	
	ft_calloc(count, sizeof(char));
}
