/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:54:27 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/08 13:54:56 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find_first(t_list *list, void *element,
			bool (*predicate)(void *, void *))
{
	while (list != NULL)
	{
		if (predicate != NULL && predicate(list->content, element) == true)
		{
			return (list);
		}
		list = list->next;
	}
	return (NULL);
}
