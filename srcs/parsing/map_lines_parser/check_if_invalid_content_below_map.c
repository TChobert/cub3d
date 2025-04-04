/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_invalid_content_below_map.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:55:15 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/04 17:04:48 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static size_t	find_last_full_line_in_file(t_game_data *game_data)
{
	size_t	i;

	i = game_data->map_file_lines_number - 1;
	while (i > game_data->current_line)
	{
		if (game_data->map_file_content[i] != NULL
			&& !is_empty_line(game_data->map_file_content[i]))
			return (i);
		i--;
	}
	return (game_data->current_line);
}

void	check_if_invalid_content_below_map(t_game_data *game_data)
{
	size_t	last_full_line_index;

	last_full_line_index = find_last_full_line_in_file(game_data);
	if (is_map_last_line(
			game_data->map_file_content[last_full_line_index]) == false)
	{
		ft_dprintf(STDERR_FILENO,
			"Error\nInvalid content below map detected.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
}
