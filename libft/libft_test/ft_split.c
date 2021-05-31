#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	unsigned int	start_i;
	unsigned int	str_i;

	if (*s == 0)
		return (0);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	if (strlen(s) <= start)
		return (str);
	str_i = 0;
	start_i = start;
	while (len)
	{
		*(str + str_i) = *(s + start_i);
		str_i++;
		start_i++;
		len--;
	}
	*(str + str_i) = '\0';
	return (str);
}
int		ft_word_cnt(char const *s, char c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if (s[i] == c)
				i++;
			else
			{
				while (s[i] != c && s[i] != 0)
					i++;
				cnt++;
			}
		}
	}
	return (cnt);
}
void	ft_free(char **res, int word)
{
	int i;

	i = 0;
	while (i < word)
	{
		free(res[i]);
		i++;
	}
}

char	**ft_split2(char **res, char const *s, char c, int word)
{
	int	i;
	int	idx;
	int	end;

	i = 0;
	idx = 0;
	while (s[i])
	{
//		printf("1: %c\n", s[i]);
		if (s[i] == c)
			i++;
		else
		{
			end = i;
	//		printf("2: %c\n", s[end]);
			while (s[end] != c && s[end] != 0)
				end++;
			res[idx++] = (char *)malloc(end - i + 1);
			if (!res[idx - 1])
			{
				ft_free(res, word + 1);
				free(res);
				return (0);
			}
			res[idx - 1] = ft_substr(s, i, end - i);
			i = end;
		//	printf("arr; %s\n", arr[idx - 1]);
		}
	}
	res[idx] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word;

	word = ft_word_cnt(s, c);
//	printf("%d\n", word);
	res = (char **)malloc(sizeof(char *) * (word + 1));
	if (!res)
		return(0);
	res = ft_split2(res, s, c, word);
	if (!res)
	{
//		ft_free(res, word + 1);
//		free(res);
		return (0);
	}
	return (res);
}
int main()
{
	char	**tab;
   	tab = ft_split("  tripouille  42  ", ' ');
//	printf("%s\n", tab);
	printf("%s\n", tab[0]);	
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);

}
