/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:41:39 by seopark           #+#    #+#             */
/*   Updated: 2021/05/17 20:08:14 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\r' || c == '\n' ||
			c == '\v' || c == '\f' || c == ' ')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	char		*s;
	long long	num;
	int			minus;

	s = (char *)str;
	while (ft_isspace(*s) == 1)
		s++;
	minus = 1;
	if (*s == '-')
		minus = -1;
	if (*s == '-' || *s == '+')
		s++;
	num = 0;
	while (ft_isdigit(*s))
	{
		if (num > 2147483647)
			return (-1);
		else if (num < -2147483648)
			return (0);
		else
			num = num * 10 + (*s - '0');
		s++;
	}
	return ((int)(num * minus));
}
