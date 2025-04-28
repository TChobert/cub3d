/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_released.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:23:40 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/24 20:24:00 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

int	on_key_released(int keycode, void *param)
{
	t_game_data	*game_data;

	game_data = (t_game_data *)param;
	if (keycode == W_KEY)
		game_data->player_inputs.w = KEY_FREE;
	else if (keycode == S_KEY)
		game_data->player_inputs.s = KEY_FREE;
	else if (keycode == A_KEY)
		game_data->player_inputs.a = KEY_FREE;
	else if (keycode == D_KEY)
		game_data->player_inputs.d = KEY_FREE;
	else if (keycode == LEFT_ARROW)
		game_data->player_inputs.left_arrow = KEY_FREE;
	else if (keycode == RIGHT_ARROW)
		game_data->player_inputs.right_arrow = KEY_FREE;
	return (SUCCESS);
}

//ESC ??