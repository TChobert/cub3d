/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:25:57 by tchobert          #+#    #+#             */
/*   Updated: 2024/08/05 14:28:59 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t size)
{
	char	*duplicated_str;

	duplicated_str = (char *)malloc(sizeof(char) * (size + 1));
	if (duplicated_str != NULL)
	{
		ft_strncpy(duplicated_str, src, size);
	}
	return (duplicated_str);
}
