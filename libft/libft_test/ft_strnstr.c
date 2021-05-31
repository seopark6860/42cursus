#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[h] != 0)
	{
		printf("1 :   %c %c\n", haystack[h], needle[n]);
		while (haystack[h + n] == needle[n] && h + n < len)
		{
			printf("2 :  %c %c\n", haystack[h + n], needle[n]);
			n++;
			if (needle[n] == 0)
				return ((char *)(haystack + h));
		}
		h++;
		n = 0;
	}
	return (0);
}
// "" -> haystack
// 널 포인터 -> seg
int main()
{
//	printf("%s\n", strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZ",9));
//	printf("%s\n", ft_strnstr("MZIRIBMZIRIBMZE123", "MZIRIBMZ", 9));
	printf("%s\n", strnstr("see FF your FF return FF now FF", "FF", strlen("see FF your FF return FF now FF")));
	printf("%s\n", ft_strnstr("see FF your FF return FF now FF", "FF", strlen("see FF your FF return FF now FF")));
}
