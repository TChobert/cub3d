/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:42:54 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/09 16:08:52 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_content_status	parse_map_file(t_game_data *game_data)
{
	get_file_content(game_data);
	get_textures_and_colors(game_data);
	get_map(game_data);
	if (check_if_valid_map(&game_data->game_map) == INVALID_CONTENT)
	{
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	return (VALID_CONTENT);
}
