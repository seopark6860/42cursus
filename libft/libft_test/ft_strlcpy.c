#include <stdio.h>
#include <string.h>

size_t	f_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t idx;
	size_t len;

	if (!src)
		return (0);
	len = f_strlen(src);
	if (dstsize)
	{
		idx = 0;
		while (idx < dstsize - 1 && src[idx] != '\0')
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (len);
}

int main(){
//	char	d[] = "123456";
//	char	s[] = 0;
	char	dd[] = "123456";
//	char	ss[] = 0;

//	printf("%zu\n", strlcpy(d, 0, 3));
	printf("%zu\n", ft_strlcpy(dd, 0, 3));
}
