/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_strs_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:27:55 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/23 16:29:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_strs_array(char **array, int fd)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putstr_fd(array[i], fd);
		ft_putchar_fd('\n', fd);
		++i;
	}
}
