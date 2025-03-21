/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_previous_element.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:59:17 by tchobert          #+#    #+#             */
/*   Updated: 2025/02/16 22:59:27 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find_previous_element(t_list *lst, t_list *node)
{
	t_list	*previous_element;

	if (lst != NULL)
	{
		previous_element = lst;
		while (previous_element != NULL)
		{
			if (previous_element->next == node)
			{
				return (previous_element);
			}
			previous_element = previous_element->next;
		}
	}
	return (NULL);
}
