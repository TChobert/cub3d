/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:14:48 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/22 14:15:00 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

static void	setup_mlx_hooks(t_game_data *game_data)
{
	mlx_hook(game_data->mlx_data.win_ptr, DestroyNotify, NoEventMask, on_close_window,
		game_data);
	mlx_hook(game_data->mlx_data.win_ptr, KeyPress, KeyPressMask, on_key_press,
		game_data);
}

void	init_game(t_game_data *game_data)
{
	if (init_mlx_data(&game_data->mlx_data) == FAILURE)
	{
		ft_dprintf(STDERR_FILENO, "Error\nFailed to initialize mlx.\n");
		game_exit_routine(game_data);
		exit(FAILURE);
	}
	setup_mlx_hooks(game_data);
}
