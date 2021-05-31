#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*strdup(const char *s1)
{
	char	*arr;
	int		len;

	len = strlen(s1);
	arr = (char	*)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	memcpy(arr, s1, len + 1);
	return (arr);	
}
int main()
{

}
