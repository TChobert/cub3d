/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:42:54 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/26 17:43:11 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

//open_map_file -> le fd dans game_data

// static void	duplicate_file_content(t_game_data *game_data)
// {
// 	//copie le truc -> game_data(un champ pour ca)
// 	//close le map_fd
// }

t_content_status	parse_map_file(t_game_data *game_data)
{
	duplicate_file_content(game_data);
	if (get_textures_and_colors(game_data) == INVALID_CONTENT ||
			get_map_content(game_data) == INVALID_CONTENT)
	{
		return (PARSE_ERROR);
	}
	return (PARSE_SUCCESS);
}