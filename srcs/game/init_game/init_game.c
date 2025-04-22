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

static void	set_default_window_size(t_mlx_data *mlx)
{
	mlx->win_width = WIN_WIDTH;
	mlx->win_height = WIN_HEIGHT;
}

static int	init_mlx_data(t_mlx_data *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (mlx_data->mlx_ptr == NULL)
		return (FAILURE);
	set_default_window_size(mlx_data);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr,
		mlx_data->win_width, mlx_data->win_height,
		"Cub3D");
	if (mlx_data->win_ptr == NULL)
		return (FAILURE);
	return (SUCCESS);
}

void	init_game(t_game_data *game_data)
{
	if (init_mlx_data(&game_data->mlx_data) == FAILURE)
	{
		ft_dprintf(STDERR_FILENO, "Error\nFailed to initialize MLX.\n");
		game_exit_routine(game_data);
		exit(FAILURE);
	}
}
