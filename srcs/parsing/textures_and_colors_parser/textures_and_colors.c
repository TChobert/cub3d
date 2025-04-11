/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:57 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/02 12:16:20 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static void	check_textures_and_colors_are_valid(t_parse_data *parse_data)
{
	check_textures(parse_data);
	check_colors(parse_data);
}

void	get_textures_and_colors(t_parse_data *parse_data)
{
	t_parse_state	parse_state;

	parse_state.state = EMPTY_LINE;
	while (parse_state.state != END_OF_PROCESS
		&& parse_data->current_line < parse_data->map_file_lines_number)
	{
		run_state(parse_data, &parse_state);
	}
	check_textures_and_colors_are_valid(parse_data);
}

//return (fonction de fin de processus); fonction de fin fait son taff
//et retourne un t_content_status selon ce qu'elle a trouve

//check_colors(parse_data); en 2eme ligne de
//check_textures_and_colors_are_valid
