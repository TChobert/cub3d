/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_first_content_match.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:49:32 by tchobert          #+#    #+#             */
/*   Updated: 2025/01/08 15:49:48 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_list_find_first_content_match(t_list *list, void *element,
			bool (*predicate)(void *, void *))
{
	const t_list	*matched_node = ft_list_find_first(list, element,
			predicate);

	if (matched_node == NULL)
		return (NULL);
	return (matched_node->content);
}
