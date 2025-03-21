/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:07:52 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/27 13:05:04 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*new_area;
	const size_t	total_size = (nmemb * size);

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
	{
		return (NULL);
	}
	new_area = (void *)malloc(total_size);
	if (new_area != NULL)
	{
		ft_bzero(new_area, total_size);
	}
	return (new_area);
}

/*
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char	*ptr = ft_calloc(10000000000, sizeof(char));
	if (ptr == NULL)
	{
		return (- 1);
	}
	for (int i = 0; i < 10000000000; ++i)
	{
		printf("%d", ptr[i]);
	}
	printf("\n");
	return (EXIT_SUCCESS);
}
*/
