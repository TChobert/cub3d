/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:27:29 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/23 19:27:44 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
int	main(int ac, char **av)
{
	(void)ac;
	printf("mine = %d\n", ft_isprint(atoi(av[1])));
	printf("true = %d\n", isprint(atoi(av[1])));
	return (EXIT_SUCCESS);
}
*/
