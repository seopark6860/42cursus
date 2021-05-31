#include <stdlib.h>
#include <stdio.h>

char	*ft_strmapi(char const *s, char *(f)(unsigned int, char))
{
	char			*arr;
	unsigned int	len;
	unsigned int	i;

	if (!s)		// protect
		return (0);
	len = strlen(s);
	arr = (char *)malloc(len + 1);
	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

int main()
{
	printf("%s\n", ft_strmapi());
}
