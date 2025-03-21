/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:47:24 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 12:00:21 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_byte	*current_s1 = (const t_byte *)s1;
	const t_byte	*current_s2 = (const t_byte *)s2;
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (current_s1[i] != current_s2[i])
		{
			return (current_s1[i] - current_s2[i]);
		}
		++i;
	}
	return (0);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	printf("mine = %d\n", ft_memcmp(av[1], av[2], atoi(av[3])));
	printf("true = %d\n", memcmp(av[1], av[2], atoi(av[3])));
	return (EXIT_SUCCESS);
}
*/
