/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:46:55 by seopark           #+#    #+#             */
/*   Updated: 2021/05/17 15:57:13 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int start;

	start = 0;
	while (s1[start])
	{
		if (ft_strchr(set, s1[start]))
			start++;
		else
			break ;
	}
	return (start);
}

static int	ft_end(char const *s1, char const *set)
{
	int end;

	end = ft_strlen(s1);
	while (0 < end && s1[end - 1])
	{
		if (ft_strchr(set, s1[end - 1]))
			end--;
		else
			break ;
	}
	return (end);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	start;
	size_t	end;
	int		i;

	if (!s1)
		return (0);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	arr = (char *)malloc(end - start + 1);
	if (!arr)
		return (0);
	i = 0;
	while (start < end)
	{
		arr[i] = s1[start];
		i++;
		start++;
	}
	arr[i] = '\0';
	return (arr);
}
