/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:51:47 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 11:51:53 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;
	char	*occurence;

	i = 0;
	s_len = ft_strlen(s) + 1;
	occurence = NULL;
	while (i < s_len)
	{
		if (s[i] == (char)c)
		{
			occurence = (char *)(s + i);
			return (occurence);
		}
		++i;
	}
	return (occurence);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	printf("%p\n", ft_strchr(av[1], atoi(av[2])));
	printf("%s\n", ft_strchr(av[1], atoi(av[2])));
	return (EXIT_SUCCESS);
}
*/
