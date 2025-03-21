/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:56:19 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 11:56:26 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char )s1[i] - (unsigned char )s2[i]);
		}
		++i;
	}
	return (0);
}

/*
int	main(int ac, char **av)
{
	(void)ac;
	printf("mine = %d\n", ft_strncmp(av[1], av[2], atoi(av[3])));
	printf("true = %d\n", strncmp(av[1], av[2], atoi(av[3])));
	return (EXIT_SUCCESS);
}
*/
