/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_character_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:29:00 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/11 19:47:00 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

void	transfer_character_data(t_game_data *game_data,
			t_parse_data *parse_data)
{
	game_data->character.position.x
		= parse_data->game_map.character_data.character_coords[1];
	game_data->character.position.y
		= parse_data->game_map.character_data.character_coords[0];
	game_data->character.orientation
		= parse_data->game_map.character_data.character_orientation;
}
