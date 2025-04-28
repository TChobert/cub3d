/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:14:06 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/23 18:21:30 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

int move_forward(t_game_data *game_data)
{
	const double new_x = game_data->character.position.x
		+ game_data->character.direction.x * MOVE_SPEED;
	const double new_y = game_data->character.position.y
		+ game_data->character.direction.y * MOVE_SPEED;

	if (is_valid_move(game_data, new_x, new_y))
	{
		game_data->character.position.x = new_x;
		game_data->character.position.y = new_y;
	}
	return (SUCCESS);
}

int move_backward(t_game_data *game_data)
{
	const double new_x = game_data->character.position.x
		- game_data->character.direction.x * MOVE_SPEED;
	const double new_y = game_data->character.position.y
		- game_data->character.direction.y * MOVE_SPEED;

	if (is_valid_move(game_data, new_x, new_y))
	{
		game_data->character.position.x = new_x;
		game_data->character.position.y = new_y;
	}
	return (SUCCESS);
}

int move_right(t_game_data *game_data)
{
	const double new_x = game_data->character.position.x
		+ game_data->character.plane.x * MOVE_SPEED;
	const double new_y = game_data->character.position.y
		+ game_data->character.plane.y * MOVE_SPEED;

	if (is_valid_move(game_data, new_x, new_y))
	{
		game_data->character.position.x = new_x;
		game_data->character.position.y = new_y;
	}
	return (SUCCESS);
}

int move_left(t_game_data *game_data)
{
	const double new_x = game_data->character.position.x
		- game_data->character.plane.x * MOVE_SPEED;
	const double new_y = game_data->character.position.y
		- game_data->character.plane.y * MOVE_SPEED;

	if (is_valid_move(game_data, new_x, new_y))
	{
		game_data->character.position.x = new_x;
		game_data->character.position.y = new_y;
	}
	return (SUCCESS);
}
