/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_errors_messages.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:28:18 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/07 17:28:46 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

void	no_error(const char *invalid_element)
{
	(void)invalid_element;
}

void	invalid_id(const char *invalid_element)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s: invalid element.\n",
		invalid_element);
}

void	invalid_xpm(const char *invalid_element)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s: is not a XPM file.\n",
		invalid_element);
}

void	is_not_a_path(const char *invalid_element)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s: not a valid path.\n",
		invalid_element);
}

void	double_element(const char *invalid_element)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s: is present twice.\n",
		invalid_element);
}
