/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:41:28 by seopark           #+#    #+#             */
/*   Updated: 2021/05/05 15:51:51 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

int		ft_len(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
char	*ft_strrchr(const char *s, int c)
{
	int	len;
	int i;

	len = ft_len(s);
	i = 0;
	while (len - i >= 0)
	{
		if (s[len - i] == c)
		{
			return ((char *)(s + len - i));
		}
		i++;
	}
	return (0);
}
int main(){
	printf("%p\n", strrchr("abcdcdcd", 98));
	printf("%s\n", strrchr("abcdcdcd", 98));
	printf("%p\n", ft_strrchr("abcdcdcd", 98));
	printf("%s\n", ft_strrchr("abcdcdcd", 98));
}
