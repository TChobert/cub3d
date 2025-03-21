/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:57:45 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 12:01:41 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static char	*ft_strndup(char *s, size_t n)
{
	size_t	i;
	char	*duplicated;

	i = 0;
	duplicated = (char *)malloc(sizeof(char) * (n + 1));
	if (duplicated != NULL)
	{
		while (i < n && s[i] != '\0')
		{
			duplicated[i] = s[i];
			++i;
		}
		duplicated[i] = '\0';
	}
	return (duplicated);
}
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start + len > s_len)
	{
		len = s_len - start;
	}
	if (start > s_len)
	{
		return (ft_strdup(""));
	}
	substring = (char *)malloc(sizeof(char) * len + 1);
	if (substring != NULL)
	{
		ft_strlcpy(substring, (char *)s + start, len + 1);
	}
	return (substring);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	printf("%s\n", ft_substr(av[1], atoi(av[2]), atoi(av[3])));
	printf("%p\n", ft_substr(av[1], atoi(av[2]), atoi(av[3])));
	return (EXIT_SUCCESS);
}
*/
