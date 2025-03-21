/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:49:04 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 11:49:13 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	t_byte			*current;
	size_t			i;

	current = (t_byte *)s;
	i = 0;
	while (i < n)
	{
		current[i] = (t_byte)c;
		++i;
	}
	return (s);
}

/*
int main(void)
{
	char	array[] = "AAAAA";
	char	array2[] = "AAAAA";
	ft_memset(array + 2, 86, 3);
	memset(array2 + 2, 86, 3);
	printf("mine = %s\n", array);
	printf("true = %s\n", array2);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	int	count = 0;
	int	array[] = {1, 2, 3};
	int	array2[] = {1, 2, 3};
	int size = sizeof(int) * 3;
	while (count < 3)
	{
		printf("%d", array[count]);
		++count;
	}
	printf("\n");
	ft_memset(array, 'A', size);
	count = 0;
	printf("mine =");
	while (count < 3)
	{
		printf("%d", array[count]);
		++count;
	}
	printf("\n");
	memset(array2, 'A', size);
	count = 0;
	printf("true =");
	while (count < 3)
	{
		printf("%d", array2[count]);
		++count;
	}
	printf("\n");
	return (EXIT_SUCCESS);
}
*/
