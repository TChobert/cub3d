/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:43:03 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/02 18:53:32 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static bool	is_color_missing(t_colors colors)
{
	if (colors.floor.is_full == false || colors.ceiling.is_full == false)
	{
		return (true);
	}
	return (false);
}

void	check_colors(t_game_data *game_data)
{
	if (is_color_missing(game_data->colors) == true)
	{
		if (game_data->parse_error_info.error_type != NO_ERROR)
		{
			ft_dprintf(STDERR_FILENO, "Error\n%s: invalid color.\n",
				game_data->parse_error_info.invalid_element);
		}
		else
			ft_dprintf(STDERR_FILENO, "Error\nA color is missing.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
}


