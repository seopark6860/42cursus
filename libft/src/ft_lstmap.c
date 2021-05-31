/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:00:21 by seopark           #+#    #+#             */
/*   Updated: 2021/05/17 16:10:18 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *temp;
	t_list *ptr;

	if (!lst)
		return (0);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
		return (0);
	ptr = temp;
	lst = lst->next;
	while (lst)
	{
		ptr->next = ft_lstnew(f(lst->content));
		if (!(ptr->next))
		{
			ft_lstclear(&temp, del);
			return (0);
		}
		lst = lst->next;
		ptr = ptr->next;
	}
	return (temp);
}
