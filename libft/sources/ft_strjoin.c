/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:53:01 by tchobert          #+#    #+#             */
/*   Updated: 2024/08/02 18:28:21 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_joined;

	str_joined = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		str_joined = (char *)malloc(sizeof(char) * (ft_strlen(s1)
					+ ft_strlen(s2) + 1));
		if (str_joined != NULL)
			str_joined = ft_strcat(ft_strcpy(str_joined, s1), s2);
	}
	else if (s1 != NULL)
		str_joined = ft_strdup(s1);
	else if (s2 != NULL)
		str_joined = ft_strdup(s2);
	return (str_joined);
}
