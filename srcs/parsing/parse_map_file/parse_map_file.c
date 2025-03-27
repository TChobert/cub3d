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

t_content_status	parse_map_file(t_game_data *game_data)
{
	extract_file_content(game_data);
	// if (get_textures_and_colors(game_data) == INVALID_CONTENT
	// 		|| get_map(game_data) == INVALID_CONTENT)
	// {
	// 	return (INVALID_CONTENT);
	// }
	return (VALID_CONTENT);
}
