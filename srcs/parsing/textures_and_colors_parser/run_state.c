/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:59:00 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/28 18:41:30 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static void	save_error_type(t_error_nature error_nature, t_game_data *game_data)
{
	game_data->parse_error_type.error_nature = error_nature;
	game_data->parse_error_type.invalid_field
		= ft_strdup(game_data->map_file_content[game_data->current_line]);
}

static void	state_full(t_game_data *game_data, t_parse_state *parse_state)
{
	t_texture_element	*texture_type;

	texture_type = get_texture_type(
			game_data->map_file_content[game_data->current_line]);
	if (texture_type == NULL)
	{
		save_error_type(INVALID_ID, game_data);
		parse_state->state = COMPLETE;
		return ;
	}
	if (get_texture(game_data,
			game_data->map_file_content[game_data->current_line],
			texture_type) == INVALID_TEXTURE)
	{
		game_data->parse_error_type.invalid_field
			= ft_strdup(game_data->map_file_content[game_data->current_line]);
		parse_state->state = COMPLETE;
		return ;
	}
	parse_state->state = EMPTY_LINE;
	++game_data->current_line;
}

static void	state_empty(t_game_data *game_data, t_parse_state *parse_state)
{
	if (is_empty_line(game_data->map_file_content[game_data->current_line])
		== true)
	{
		++game_data->current_line;
		return ;
	}
	else
		parse_state->state = FULL_LINE;
}

void	run_state(t_game_data *game_data, t_parse_state *parse_state)
{
	static t_state_func	state_functions[] = {
		state_empty,
		state_full,
	};

	state_functions[parse_state->state](game_data, parse_state);
}
