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

int	on_key_press(int keycode, void *param)
{
	t_game_data	*game_data;

	game_data = (t_game_data *)param;
	if (keycode == ESC_KEY)
		on_close_window(param);
	else if (keycode == W_KEY)
		move_forward(game_data);
	else if (keycode == S_KEY)
		move_backward(game_data);
	else if (keycode == A_KEY)
		move_left(game_data);
	else if (keycode == D_KEY)
		move_right(game_data);
	else if (keycode == LEFT_ARROW)
		rotate_left(game_data);
	else if (keycode == RIGHT_ARROW)
		rotate_right(game_data);
	return (SUCCESS);
}
