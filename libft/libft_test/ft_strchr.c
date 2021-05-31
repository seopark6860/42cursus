/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:41:28 by seopark           #+#    #+#             */
/*   Updated: 2021/05/12 14:07:49 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int ft_len(const char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		i++;
	}
	return (i);
}

char *ft_strchr(const char *s, int c)
{
	int len;
	int i;

	len = ft_len(s);
	i = 0;
	while(i <= len)
	{
		if(s[i] == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (0);
}

int main()
{
//	printf("%p\n", strchr("", 0));
	printf("%s\n", strchr("tripouille", 't' + 256));
//	printf("%p\n", ft_strchr("",0));
	printf("%s\n", ft_strchr("tripouille", 't' + 256));
	printf("c : %c\n", 't' + 256);
}
