/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_color_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:24:40 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/02 14:53:28 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static size_t	count_commas(t_color color_string)
{
	size_t	i;
	size_t	nb_commas;

	i = 0;
	while (color_string[i])
	{
		if (color_string[i] == ',')
			nb_commas++;
		i++;
	}
	return (nb_commas);
}

static	bool	check_number_commas(t_color color)
{
	size_t	nb_commas;

	nb_commas = count_commas(color);
	if (nb_commas != 2)
	{
		return (false);
	}
	return (true);
}

void	is_valid_color_string(t_game_data *game_data)
{
	replace_color_strings_without_spaces(game_data);
	if (check_number_commas(game_data->colors.floor_color) == false
		|| check_number_commas(game_data->colors.ceiling_color) == false)
	{
		
	}
}
