/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:24:36 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/23 19:24:48 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
int	main(int ac, char **av)
{
	(void)ac;
	printf("%d\n", ft_isdigit(av[1][0]));
	return (EXIT_SUCCESS);
}
*/
