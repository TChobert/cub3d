/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:50:51 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 11:50:57 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_long(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd_long(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + ASCII_ZERO, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr_fd_long(n, fd);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	ft_putnbr_fd(atoi(av[1]), STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
*/
