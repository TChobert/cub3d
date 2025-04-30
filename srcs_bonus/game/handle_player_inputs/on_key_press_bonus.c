/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_press_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:06:24 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:11:29 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

int	on_key_press(int keycode, void *param)
{
	t_game_data	*game_data;

	game_data = (t_game_data *)param;
	if (keycode == ESC_KEY)
		on_close_window(param);
	else if (keycode == W_KEY)
		game_data->player_inputs.w = KEY_PRESSED;
	else if (keycode == S_KEY)
		game_data->player_inputs.s = KEY_PRESSED;
	else if (keycode == A_KEY)
		game_data->player_inputs.a = KEY_PRESSED;
	else if (keycode == D_KEY)
		game_data->player_inputs.d = KEY_PRESSED;
	else if (keycode == LEFT_ARROW)
		game_data->player_inputs.left_arrow = KEY_PRESSED;
	else if (keycode == RIGHT_ARROW)
		game_data->player_inputs.right_arrow = KEY_PRESSED;
	return (SUCCESS);
}

// garder les else if pour simultaneite ?
