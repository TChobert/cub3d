/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:54:07 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/25 20:54:20 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

void	draw_frame_to_window(t_game_data *game_data)
{
	mlx_put_image_to_window(game_data->mlx_data.mlx_ptr,
		game_data->mlx_data.win_ptr, game_data->mlx_data.frame_img.img_ptr,
		0, 0);
}
