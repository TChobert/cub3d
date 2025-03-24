/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:50:54 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/24 10:52:24 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

void	print_error_message_args(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Wrong number of args\n", 2);
}
