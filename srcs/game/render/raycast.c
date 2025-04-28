/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:51:22 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/28 10:36:36 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

int	raycast(t_game_data *game_data)
{
	size_t	x;
	t_ray	ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(game_data, &ray, x);
		set_dda_data(game_data, &ray);
		launch_dda(game_data, &ray);
		calculate_line_height(game_data, &ray);
		draw_vertical_line(game_data, &game_data->mlx_data.frame_img, x, &ray);
		++x;
	}
	return (SUCCESS);
}
