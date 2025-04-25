/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:51:22 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/25 15:51:34 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

int	raycast(t_game_data *game_data)
{
	size_t	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		t_ray		ray;

		init_ray(game_data, &ray, x);
		set_dda_data(game_data, &ray);
		launch_dda(game_data, &ray);
		calculate_line_height(game_data, &ray);
		draw_vertical_line(&game_data->mlx_data.frame_img, x, &ray);
		++x;
	}
	mlx_put_image_to_window(game_data->mlx_data.mlx_ptr, game_data->mlx_data.win_ptr, game_data->mlx_data.frame_img.img_ptr, 0, 0);
	return (SUCCESS);
}
