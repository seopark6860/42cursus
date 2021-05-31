#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	start_i;
	unsigned int	str_i;

	if (*s == 0 || s == 0)
		return (0);
	if (strlen(s) <= start)
		return (strdup(""));
	if (start + len > strlen(s))
		str = (char *)malloc((strlen(s) - start + 1));
	else
		str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str_i = 0;
	start_i = start;
	while (len-- && s[start_i]) // leak <s[start_i]>
	{
		str[str_i] = s[start_i];
//		printf("s : %c\n", *(s + start_i));
//		printf("%c\n", *str);
//		*str = *(s + i);
		str_i++;
		start_i++;
	}
//	*str = '\0';
	str[str_i] = '\0';
	return (str);
}

int main()
{
	char	*str = "tripouille";
	char	*res;

	res = ft_substr(str, 0, 42000);
//	printf("%s\n", ft_substr(str, 5, 10));
printf("%s\n",res);
//printf("%lu\n", strlen(res));
}
