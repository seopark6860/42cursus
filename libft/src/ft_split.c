/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:17:29 by seopark           #+#    #+#             */
/*   Updated: 2021/05/17 15:47:19 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*f_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	start_i;
	unsigned int	str_i;

	if (*s == 0)
		return (0);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str_i = 0;
	start_i = start;
	while (len-- > 0 && s[start_i])
	{
		*(str + str_i) = *(s + start_i);
		str_i++;
		start_i++;
	}
	*(str + str_i) = '\0';
	return (str);
}

static int		ft_word_cnt(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
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
	return (cnt);
}

static char		**ft_free(char **res, int idx)
{
	int i;

	i = 0;
	while (i < idx)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}

static char		**ft_split2(char **res, char const *s, char c)
{
	int	i;
	int	idx;
	int	end;

	i = 0;
	idx = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			end = i;
			while (s[end] != c && s[end] != 0)
				end++;
			res[idx++] = f_substr(s, i, end - i);
			if (!res[idx - 1])
				return (ft_free(res, idx - 1));
			i = end;
		}
	}
	res[idx] = 0;
	return (res);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		word;

	if (!s)
		return (0);
	word = ft_word_cnt(s, c);
	res = (char **)malloc(sizeof(char *) * (word + 1));
	if (!res)
		return (0);
	res = ft_split2(res, s, c);
	if (!res)
		return (0);
	return (res);
}
