/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:54:12 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 11:54:18 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
	{
		return (src_len);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	char	dst[20];
	ft_strlcpy(dst, av[1], 0);
	printf("%zu\n", ft_strlcpy(dst, av[1], 0));
	printf("%s\n", dst);
	return (EXIT_SUCCESS);
}
*/
