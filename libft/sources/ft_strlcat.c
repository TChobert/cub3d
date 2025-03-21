/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:53:47 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 11:53:56 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	total_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	total_len = dst_len + src_len;
	if (size == 0)
	{
		return (src_len);
	}
	if (size <= dst_len)
	{
		return (size + src_len);
	}
	while (i + dst_len < size - 1 && src[i] != '\0')
	{
		dst[i + dst_len] = src[i];
		++i;
	}
	dst[i + dst_len] = '\0';
	return (total_len);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	char	dst[7] = "Bjr";

	printf("%zu\n", ft_strlcat(dst, av[1], 1));
	printf("%s\n", dst);
	return (EXIT_SUCCESS);
}
*/
