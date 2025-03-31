/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:42:54 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/28 18:38:22 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_content_status	parse_map_file(t_game_data *game_data)
{
	get_file_content(game_data);
	get_textures_and_colors(game_data);
	return (VALID_CONTENT);
}

	// 		|| get_map(game_data) == INVALID_CONTENT)
	// {
	// 	return (INVALID_CONTENT);
	// }