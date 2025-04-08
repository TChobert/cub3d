/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:41:42 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/02 19:22:33 by racoutte         ###   ########.fr       */
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

static void	display_textures_error(t_parse_error_info parse_error_info)
{
	static t_texture_error_msg	textures_errors_messages[] = {
		no_error,
		invalid_id,
		invalid_xpm,
		is_not_a_path,
		double_element
	};

	textures_errors_messages[parse_error_info.error_type]
		(parse_error_info.invalid_element);
}

void	check_textures(t_game_data *game_data)
{
	if (game_data->parse_error_info.error_type != NO_ERROR
		&& game_data->textures.is_invalid_texture == true)
	{
		display_textures_error(game_data->parse_error_info);
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	else if (is_texture_missing(game_data->textures))
	{
		ft_dprintf(STDERR_FILENO, "Error\n4 textures paths and two colors"
			" in RGB format are required before any other information to "
			"start the game.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	else if (is_double_texture(game_data) == true)
	{
		ft_dprintf(STDERR_FILENO,
			"Error\nDouble texture file path detected.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
}
