/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exit_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:42:42 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/31 14:42:55 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

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
	free(game_data->parse_error_type.invalid_field);
	free_textures(&game_data->textures);
}
