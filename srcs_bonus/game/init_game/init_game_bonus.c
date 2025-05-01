/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:14:48 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:11:42 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

static void	setup_mlx_hooks(t_game_data *game_data)
{
	mlx_hook(game_data->mlx_data.win_ptr, DestroyNotify,
		NoEventMask, on_close_window, game_data);
	mlx_hook(game_data->mlx_data.win_ptr, KeyPress, KeyPressMask, on_key_press,
		game_data);
	mlx_hook(game_data->mlx_data.win_ptr, KeyRelease, KeyReleaseMask,
		on_key_released, game_data);
	mlx_hook(game_data->mlx_data.win_ptr, MotionNotify, PointerMotionMask,
		on_mouse_move, game_data);
}

void	init_game(t_game_data *game_data)
{
	if (init_mlx_data(game_data) == FAILURE)
	{
		ft_dprintf(STDERR_FILENO, "Error\nFailed to initialize MLX.\n");
		game_exit_routine(game_data);
		exit(FAILURE);
	}
	setup_mlx_hooks(game_data);
	init_character_data(game_data);
}
