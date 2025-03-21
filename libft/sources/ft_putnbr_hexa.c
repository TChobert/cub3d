/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:30:40 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/04 16:43:59 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hexa(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_putnbr_hexa(nb / 16);
		ft_putnbr_hexa(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
}
