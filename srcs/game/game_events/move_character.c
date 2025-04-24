/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:47:41 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/24 14:24:32 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

int	move_character(t_game_data *game_data)
{
	if (game_data->player_inputs.w == KEY_PRESSED)
		move_forward(game_data);
	if (game_data->player_inputs.s == KEY_PRESSED)
		move_backward(game_data);
	if (game_data->player_inputs.a == KEY_PRESSED)
		move_left(game_data);
	if (game_data->player_inputs.d == KEY_PRESSED)
		move_right(game_data);
	if (game_data->player_inputs.left_arrow == KEY_PRESSED)
		rotate_left(game_data);
	if (game_data->player_inputs.right_arrow == KEY_PRESSED)
		rotate_right(game_data);
	return (SUCCESS);
}
