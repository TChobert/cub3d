/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:48:42 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 11:48:50 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_reverse_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	const t_byte	*current_src = (const t_byte *)src;
	t_byte			*current_dest;

	i = n;
	current_dest = (t_byte *)dest;
	while (i > 0)
	{
		current_dest[i - 1] = current_src[i - 1];
		--i;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		return (ft_reverse_memcpy(dest, src, n));
	}
	return (ft_memcpy(dest, src, n));
}

/*
int main(void)
{
	char	str[] = "Hello World !";
	char	str2[] = "Hello World !";
	char	buffer[20];
	char	buffer2[20];

	ft_memmove(buffer, str, 7);
	memmove(buffer2, str2, 7);
	buffer[7] = '\0';
	buffer2[7] = '\0';
	printf("buffer = %s\n", buffer);
	printf("buffer2 = %s\n", buffer2);
	ft_memmove(buffer + 3, buffer, ft_strlen(buffer + 1));
	memmove(buffer2 + 3, buffer2, ft_strlen(buffer2 + 1));
	ft_memmove(buffer, "Salut", 6);
	memmove(buffer2, "Salut", 6);
	printf("buffer apres insertion : %s\n", buffer);
	printf("buffer2 apres insertion : %s\n", buffer2);

	ft_memmove(buffer, str, ft_strlen(str) + 1);
	memmove(buffer2, str, ft_strlen(str)+ 1);
	printf("bufferCC = %s\n", buffer);
	printf("buffer2CC = %s\n", buffer2);
	ft_memmove(buffer, str + 7, 6);
	memmove(buffer2, str + 7, 6);
	printf("bufferCP %s\n", buffer);
	printf("buffer2CP %s\n", buffer2);
	return (EXIT_SUCCESS);
}
*/
