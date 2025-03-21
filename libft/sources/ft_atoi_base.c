/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:06:03 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/06 10:58:21 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BASE_REFERENCE "0123456789abcdef"
#define INVALID_NUMBER 1
#define VALID_NUMBER 0

static int	get_indexes(const char c)
{
	int	i;

	i = 0;
	while (c != BASE_REFERENCE[i])
	{
		++i;
	}
	return (i);
}

static int	get_char_validity(char c, unsigned int base)
{
	unsigned int	i;

	i = 0;
	while (BASE_REFERENCE[i] != '\0' && i < base)
	{
		if (BASE_REFERENCE[i] == c)
		{
			return (VALID_NUMBER);
		}
		++i;
	}
	return (INVALID_NUMBER);
}

static int	check_number(const char *nb, unsigned int base)
{
	unsigned int	i;

	i = 0;
	while (nb[i] != '\0')
	{
		if (get_char_validity(nb[i], base) == INVALID_NUMBER)
		{
			return (INVALID_NUMBER);
		}
		++i;
	}
	return (VALID_NUMBER);
}

int	ft_atoi_base(const char *nb, unsigned int base)
{
	int	i;
	int	number;
	int	sign;

	if (base < 2 || base > 16 || nb == NULL)
		return (0);
	number = 0;
	sign = (nb[0] == '-');
	i = sign;
	if (check_number(nb + i, base) == INVALID_NUMBER)
		return (0);
	while (nb[i] != '\0')
	{
		number = number * base + (get_indexes(nb[i]));
		++i;
	}
	if (sign == 1)
		number *= -1;
	return (number);
}
/*
int	main(int ac, char **av)
{
//	char	*nbr = NULL;
//	int		nb;

//	nb = ft_atoi_base(nbr, 10);
//	printf("%d\n", nb);
	if (ac != 3)
		return (EXIT_FAILURE);
	printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
	return (EXIT_SUCCESS);
}
*/
