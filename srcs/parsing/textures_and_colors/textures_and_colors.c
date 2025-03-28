/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:57 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/28 15:27:07 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

bool	is_empty_line(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

static void	state_empty(t_game_data *game_data, t_parse_state *parse_state)
{
	if (is_empty_line(game_data->map_file_data[game_data->current_line]) == true)
	{
		return (++game_data->current_line);
	}
	else
		parse_state->state = FULL_LINE;
}

t_content_status	run_state(t_game_data *game_data, t_parse_state *parse_state)
{
	static state_function	state_functions[] = {
		state_empty,
		state_full,
	};

	return (state_functions[parse_state->state]);
}

t_content_status	get_textures_and_colors(t_game_data *game_data)
{
	t_parse_state	parse_state;
	size_t	i;

	i = 0;
	parse_state.state = EMPTY_LINE;
	while (parse_state.state != END)
	{
		run_state(game_data, &parse_state);
		// if (is_empty_line(game_data->map_file_data[i]) == false)
		// {
		// 	if (parse_line_data(game_data->map_file_data[i]) == INVALID_CONTENT)
		// 		return (INVALID_CONTENT);
		// 	if (game_data->textures_and_colors == TEXTURES_OK)
		// 		return (VALID_CONTENT);
		// }
		// i++;
	}
	//return (fonction de fin de processus); fonction de fin fait son taff et retourne un t_content_status selonn ce qu'elle a trouve
}
