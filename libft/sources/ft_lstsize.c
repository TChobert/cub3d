/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:44:32 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 16:49:35 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lst_size;

	lst_size = 0;
	while (lst != NULL)
	{
		++lst_size;
		lst = lst->next;
	}
	return (lst_size);
}
/*
void	ft_print_member_content(void *content)
{
	printf("%c\n",*((char *)(content)));
	ft_putchar_fd('\n', STDOUT_FILENO);
}

int	main(void)
{
	char		list[] = "liste";
	const size_t	size = ft_strlen(list);
	size_t			i;
	t_list			*head;
	t_list			*current;
	
	i = 0;
	head = ft_lstnew(list + i);
	while (i + 1 < size)
	{
		++i;
		printf("i = %zu\n", i);
		current = ft_lstnew(list + i);
		ft_lstadd_back(&head, current); 
	}
	ft_lstiter(head, ((void (*)(void *))ft_print_member_content));
	printf("%d\n", ft_lstsize(head));
}
*/
