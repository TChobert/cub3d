/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_null.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:03:41 by tchobert          #+#    #+#             */
/*   Updated: 2024/08/05 19:07:14 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_and_null(char **strs_array)
{
	size_t	i;

	i = 0;
	while (strs_array[i] != NULL)
	{
		free(strs_array[i]);
		strs_array[i] = NULL;
		++i;
	}
	free(strs_array);
	strs_array = NULL;
}
