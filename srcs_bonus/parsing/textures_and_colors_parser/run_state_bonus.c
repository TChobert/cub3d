/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_state_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:59:00 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:09:19 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

static void	state_color(t_parse_data *parse_data, t_parse_state *parse_state)
{
	t_color_element	*color_type;

	color_type = get_color_type(
			parse_data->map_file_content[parse_data->current_line]);
	if (color_type == NULL)
	{
		save_error_type(INVALID_ID, parse_data);
		parse_state->state = END_OF_PROCESS;
		return ;
	}
	if (get_color(parse_data, parse_data
			->map_file_content[parse_data->current_line],
			color_type) == INVALID_COLOR)
	{
		parse_state->state = END_OF_PROCESS;
		return ;
	}
	parse_state->state = EMPTY_LINE;
	++parse_data->current_line;
}

static void	state_texture(t_parse_data *parse_data, t_parse_state *parse_state)
{
	t_texture_element	*texture_type;

	texture_type = get_texture_type(
			parse_data->map_file_content[parse_data->current_line]);
	if (texture_type == NULL)
	{
		parse_state->state = COLOR;
		return ;
	}
	if (get_texture(parse_data,
			parse_data->map_file_content[parse_data->current_line],
			texture_type) == INVALID_TEXTURE)
	{
		parse_state->state = END_OF_PROCESS;
		return ;
	}
	parse_state->state = EMPTY_LINE;
	++parse_data->current_line;
}

static void	state_empty_line(t_parse_data *parse_data,
				t_parse_state *parse_state)
{
	if (is_empty_line(parse_data->map_file_content[parse_data->current_line])
		== true)
	{
		++parse_data->current_line;
		return ;
	}
	else
		parse_state->state = TEXTURE;
}

void	run_state(t_parse_data *parse_data, t_parse_state *parse_state)
{
	static t_state_func	state_functions[] = {
		state_empty_line,
		state_texture,
		state_color,
	};

	state_functions[parse_state->state](parse_data, parse_state);
}

// Si get texture type == NULL -> On passe en state color.
//Sate color recherche de quelle couleur il s'agit.
// si il n'en trouve pas, alors la on passe a l'etat de fin de process
