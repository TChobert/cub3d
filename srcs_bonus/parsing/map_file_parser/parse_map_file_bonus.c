/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:42:54 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:10:36 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

t_content_status	parse_map_file(t_parse_data *parse_data)
{
	get_file_content(parse_data);
	get_textures_and_colors(parse_data);
	get_map(parse_data);
	if (check_if_valid_map(&parse_data->game_map) == INVALID_CONTENT)
	{
		parser_exit_routine(parse_data);
		exit(FAILURE);
	}
	return (VALID_CONTENT);
}
