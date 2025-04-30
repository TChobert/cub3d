/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_color_string_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:24:40 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:09:03 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

static bool	is_valid_color_char(const char *color)
{
	size_t	i;

	i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]) && color[i] != ',' && !ft_isspace(color[i]))
			return (false);
		i++;
	}
	return (true);
}

static size_t	count_commas(const char *color)
{
	size_t	i;
	size_t	nb_commas;

	i = 0;
	nb_commas = 0;
	while (color[i])
	{
		if (color[i] == ',')
			nb_commas++;
		i++;
	}
	return (nb_commas);
}

static	bool	check_number_commas(const char *color)
{
	size_t	nb_commas;

	nb_commas = count_commas(color);
	if (nb_commas != 2)
	{
		return (false);
	}
	return (true);
}

t_color_status	is_valid_color_string(const char *color)
{
	if (is_valid_color_char(color) == false)
	{
		return (INVALID_COLOR);
	}
	if (check_number_commas(color) == false)
	{
		return (INVALID_COLOR);
	}
	return (VALID_COLOR);
}
