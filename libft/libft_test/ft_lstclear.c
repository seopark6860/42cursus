void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	if (!lst)
		return ;
	while (temp != 0)
	{
		(*lst) = (*lst)->next;
		del(temp->content);
		free(lst);
		temp = *lst;
	}
}
