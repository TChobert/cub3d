/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:14:06 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/23 17:14:40 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

int	move_forward(t_game_data *game_data)
{
	game_data->character.position.x += game_data->character.direction.x * MOVE_SPEED;
	game_data->character.position.y += game_data->character.direction.y * MOVE_SPEED;
	return (SUCCESS);
}

int	move_backward(t_game_data *game_data)
{
	game_data->character.position.x -= game_data->character.direction.x * MOVE_SPEED;
	game_data->character.position.y -= game_data->character.direction.y * MOVE_SPEED;
	return (SUCCESS);
}

int	move_right(t_game_data *game_data)
{
	game_data->character.position.x += game_data->character.plane.x * MOVE_SPEED;
	game_data->character.position.y += game_data->character.plane.y * MOVE_SPEED;
	return (SUCCESS);
}

int	move_left(t_game_data *game_data)
{
	game_data->character.position.x -= game_data->character.plane.x * MOVE_SPEED;
	game_data->character.position.y -= game_data->character.plane.y * MOVE_SPEED;
	return (SUCCESS);
}
