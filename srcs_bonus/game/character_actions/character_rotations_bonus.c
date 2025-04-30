/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_rotations_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:41:02 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:11:05 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

void	rotate_right(t_game_data *game_data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game_data->character.direction.x;
	old_plane_x = game_data->character.plane.x;
	game_data->character.direction.x = game_data->character.direction.x
		* cos(ROT_SPEED) - game_data->character.direction.y * sin(ROT_SPEED);
	game_data->character.direction.y = old_dir_x
		* sin(ROT_SPEED) + game_data->character.direction.y * cos(ROT_SPEED);
	game_data->character.plane.x = game_data->character.plane.x
		* cos(ROT_SPEED) - game_data->character.plane.y * sin(ROT_SPEED);
	game_data->character.plane.y = old_plane_x
		* sin(ROT_SPEED) + game_data->character.plane.y * cos(ROT_SPEED);
}

void	rotate_left(t_game_data *game_data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game_data->character.direction.x;
	old_plane_x = game_data->character.plane.x;
	game_data->character.direction.x = game_data->character.direction.x
		* cos(ROT_SPEED) + game_data->character.direction.y * sin(ROT_SPEED);
	game_data->character.direction.y = -old_dir_x
		* sin(ROT_SPEED) + game_data->character.direction.y * cos(ROT_SPEED);
	game_data->character.plane.x = game_data->character.plane.x
		* cos(ROT_SPEED) + game_data->character.plane.y * sin(ROT_SPEED);
	game_data->character.plane.y = -old_plane_x
		* sin(ROT_SPEED) + game_data->character.plane.y * cos(ROT_SPEED);
}
