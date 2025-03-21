/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:05:22 by tchobert          #+#    #+#             */
/*   Updated: 2024/08/02 18:38:52 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *str, char sep)
{
	size_t				i;
	size_t				nb_words;
	bool				is_sep;

	is_sep = true;
	i = 0;
	nb_words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep && is_sep == true)
		{
			is_sep = false;
			++nb_words;
		}
		else if (str[i] == sep)
		{
			is_sep = true;
		}
		++i;
	}
	return (nb_words);
}
