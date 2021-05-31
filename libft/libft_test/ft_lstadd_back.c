/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:09:04 by seopark           #+#    #+#             */
/*   Updated: 2021/05/14 15:58:44 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == 0)		// *lst==0 ,, lst==0
		*lst = new;
	else
	{
		while ((*lst)->next != 0)
			*lst = (*lst)->next;
		(*lst)->next = new;
		new->next = 0;
	}
}
