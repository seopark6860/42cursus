#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = strlen(s1);
	s2_len = strlen(s2);
	arr = (char *)malloc(s1_len + s2_len + 1);
	if (!arr)
		return (0);
//	memmove(arr, s1, s1_len);
	strlcpy(arr, s1, s1_len + 1);

	printf("%s\n", arr);
//	memmove(arr + s1_len, s2, s2_len + 1);
	strlcpy(arr + s1_len, s2, s2_len);
	return (arr);
}
int main()
{
	char *s1 = "my favorite animal is";
	char *s2 = " ";
	char *s3 = "the nyancat";
	printf("%s\n", ft_strjoin(ft_strjoin(s1, s2), s3));
}
