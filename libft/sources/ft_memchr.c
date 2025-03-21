/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:46:51 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 12:00:12 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const t_byte	*current = (const t_byte *)s;
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (current[i] == (t_byte)c)
		{
			return ((void *)(current + i));
		}
		++i;
	}
	return (NULL);
}

/*
int	main(int ac, char **av)
{
	(void)ac;
	printf("mine = %p\n", ft_memchr(av[1], atoi(av[2]), strlen(av[1])));
	printf("mine = %p\n", ft_memchr(av[1], atoi(av[2]), strlen(av[1])));
	printf("true = %p\n", ft_memchr(av[1], atoi(av[2]), strlen(av[1])));
	printf("true = %p\n", ft_memchr(av[1], atoi(av[2]), strlen(av[1])));
}
*/
