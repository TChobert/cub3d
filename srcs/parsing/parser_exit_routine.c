/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exit_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:42:42 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/02 19:17:39 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

// static void	free_colors(t_colors *colors)
// {
// 	free(colors->ceiling_color);
// 	free(colors->floor_color);
// }

static void	free_textures(t_textures *textures)
{
	free(textures->east_texture);
	free(textures->north_texture);
	free(textures->south_texture);
	free(textures->west_texture);
}

void	parser_exit_routine(t_game_data *game_data)
{
	ft_free_and_null(game_data->map_file_content);
	free(game_data->parse_error_info.invalid_element);
	free_textures(&game_data->textures);
	if (game_data->game_map.map_array)
		ft_free_and_null(game_data->game_map.map_array);
}

//free_colors(&game_data->colors) a utiliser ?
