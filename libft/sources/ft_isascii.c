/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:10:30 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/27 12:57:15 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
int	main(int ac, char **av)
{
	(void)ac;
	printf("mine = %d\n", ft_isascii(atoi(av[1])));
	printf("true = %d\n", isascii(atoi(av[1])));
	return (0);
}
*/
