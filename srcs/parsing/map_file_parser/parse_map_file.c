/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:42:54 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/07 15:05:58 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_content_status	check_if_valid_map(t_map_data *map_data)
{
	if (check_if_valid_first_and_last_wall_line(map_data) == INVALID_MAP
		|| check_if_valid_map_characters(map_data) == INVALID_MAP)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid map.");
		return (INVALID_CONTENT);
	}
	return (VALID_CONTENT);
}

t_content_status	parse_map_file(t_game_data *game_data)
{
	get_file_content(game_data);
	get_textures_and_colors(game_data);
	get_map(game_data);
	if (check_if_valid_map(&game_data->game_map) == INVALID_CONTENT)
	{
		parser_exit_routine(game_data);
		return (INVALID_CONTENT);
	}
	return (VALID_CONTENT);
}

	// 		|| get_map(game_data) == INVALID_CONTENT)
	// {
	// 	return (INVALID_CONTENT);
	// }
