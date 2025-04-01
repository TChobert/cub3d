/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:41:42 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/01 16:42:09 by racoutte         ###   ########.fr       */
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

void	check_textures(t_game_data *game_data)
{
	if (is_texture_missing(game_data->textures) == true)
	{
		if (game_data->parse_error_info.error_type != NO_ERROR)
		{
			ft_dprintf(STDERR_FILENO, "Error\n%s: invalid texture.\n",
				game_data->parse_error_info.invalid_element);
		}
		else
			ft_dprintf(STDERR_FILENO, "Error\nA texture path is missing.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	if (is_double_texture(game_data) == true)
	{
		ft_dprintf(STDERR_FILENO, "Error\nDouble texture file path detected.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
}
