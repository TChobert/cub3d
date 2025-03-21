/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:37:17 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/26 16:57:43 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_node(void *content)
{
	t_list	*new_node;

	new_node = ft_lstnew(content);
	if (new_node == NULL)
		return (NULL);
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_head;
	t_list	*new_list_current;
	void	*new_content;

	new_list_head = NULL;
	if (f == NULL || del == NULL || lst == NULL)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		if (new_content == NULL)
		{
			return (ft_lstclear(&new_list_head, del), NULL);
		}
		new_list_current = create_node(new_content);
		if (new_list_current == NULL)
		{
			del(new_content);
			return (ft_lstclear(&new_list_head, del), NULL);
		}
		ft_lstadd_back(&new_list_head, new_list_current);
		lst = lst->next;
	}
	return (new_list_head);
}
