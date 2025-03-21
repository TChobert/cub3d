/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:29:51 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/23 19:30:03 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_len(long nb)
{
	size_t	size;

	size = (nb <= 0);
	while (nb != 0)
	{
		nb /= 10;
		++size;
	}
	return (size);
}

static void	fill_str_with_nbr(char *new_str, long nb, const size_t number_len)
{
	size_t	i;

	i = number_len - 1;
	if (nb == 0)
	{
		new_str[0] = '0';
	}
	else if (nb < 0)
	{
		new_str[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		new_str[i] = (nb % 10) + ASCII_ZERO;
		nb /= 10;
		--i;
	}
	new_str[number_len] = '\0';
}

char	*ft_itoa(int n)
{
	const size_t	number_len = get_number_len(n);
	char			*new_str;

	new_str = (char *)malloc(sizeof(char) * (number_len + 1));
	if (new_str != NULL)
	{
		fill_str_with_nbr(new_str, n, number_len);
	}
	return (new_str);
}
/*
int	main(int ac, char **av)
{
	char	*new_str;
	(void)ac;
	(void)av;
	new_str = ft_itoa(atoi(av[1]));
	printf("%s\n", new_str);
	printf("%zu\n", ft_strlen(new_str));
	return (EXIT_SUCCESS);
}
*/
