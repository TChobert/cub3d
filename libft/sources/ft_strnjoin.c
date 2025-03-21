/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:27:35 by tchobert          #+#    #+#             */
/*   Updated: 2024/08/05 14:27:38 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t max)
{
	char	*joined_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	s1_len = 0;
	s2_len = ft_strlen(s2);
	if (s1 != NULL)
	{
		s1_len = ft_strlen(s1);
	}
	if (s2_len > max)
	{
		s2_len = max;
	}
	total_len = s1_len + s2_len;
	joined_str = (char *)malloc(sizeof(char) *(total_len + 1));
	if (joined_str == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strncpy(joined_str, s1, s1_len);
	ft_strncpy(joined_str + s1_len, s2, s2_len);
	return (joined_str);
}
