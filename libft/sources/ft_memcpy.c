/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:47:45 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 12:05:04 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const t_byte	*current_src = (const t_byte *)src;
	t_byte			*current_dest;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	current_dest = (t_byte *)dest;
	while (i < n)
	{
		current_dest[i] = current_src[i];
		++i;
	}
	return (dest);
}

/*
int	main(int ac, char **av)
{
	(void)ac;
	char	buffer[20];
	char	buffer2[20];

	ft_memcpy(buffer, av[1], atoi(av[2]));
	memcpy(buffer2, av[1], atoi(av[2]));
	printf("mine = %s\n", buffer);
	printf("true = %s\n", buffer2);
	return (EXIT_SUCCESS);
}
*/
