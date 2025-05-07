/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:08:12 by racoutte          #+#    #+#             */
/*   Updated: 2025/05/01 19:00:55 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

void	run_game(t_game_data *game_data)
{
	init_game(game_data);
	mlx_loop_hook(game_data->mlx_data.mlx_ptr,
		game_loop, game_data);
	mlx_loop(game_data->mlx_data.mlx_ptr);
}
