/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:57 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/28 18:33:57 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static bool	is_texture_missing(t_textures textures)
{
	if (textures.east_texture == NULL || textures.west_texture == NULL)
		return (true);
	if (textures.north_texture == NULL || textures.south_texture == NULL)
		return (true);
	return (false);
}

static void	check_textures_and_colors_are_valid(t_game_data *game_data)
{
	if (is_texture_missing(game_data->textures) == true)
	{
		ft_dprintf(STDERR_FILENO, "Error\n%s: invalid texture.\n",
			game_data->parse_error_type.invalid_field);
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
}

void	get_textures_and_colors(t_game_data *game_data)
{
	t_parse_state	parse_state;

	parse_state.state = EMPTY_LINE;
	while (parse_state.state != COMPLETE
		&& game_data->current_line < game_data->map_file_lines_number)
	{
		run_state(game_data, &parse_state);
	}
	check_textures_and_colors_are_valid(game_data);
}

//return (fonction de fin de processus); fonction de fin fait son taff
//et retourne un t_content_status selon ce qu'elle a trouve