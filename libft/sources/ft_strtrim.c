/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:57:23 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 11:57:28 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_in_set(char const *set, int c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (true);
		}
		++i;
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t				start;
	size_t				end;
	char				*trimmed;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_in_set(set, s1[start]))
		++start;
	while (end > start && is_in_set(set, s1[end]))
		--end;
	trimmed = ft_substr(s1, start, end - start + 1);
	if (trimmed == NULL)
	{
		return (NULL);
	}
	return (trimmed);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	char	*trimmed;
	trimmed = ft_strtrim(av[1], av[2]);
	printf("%s\n", trimmed);
	return(EXIT_SUCCESS);
}
*/
