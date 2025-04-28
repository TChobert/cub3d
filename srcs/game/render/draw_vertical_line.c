/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:01:26 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/28 10:44:50 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

static void	draw_sky(t_game_data *game_data, t_image_data *img,
				t_ray *ray, int x)
{
	int	y;
	unsigned int color;

	color = create_color(
		game_data->floor_and_ceiling.ceiling.r,
		game_data->floor_and_ceiling.ceiling.g,
		game_data->floor_and_ceiling.ceiling.b);
	y = 0;
	while (y < ray->draw_start)
	{
		*((unsigned int *)(img->pixel_info + y * img->line_length + x
			* (img->bpp / 8))) = color;
		++y;
	}
}

static void	draw_floor(t_game_data *game_data, t_image_data *img,
				t_ray *ray, int x)
{
	int	y;
	unsigned int color;

	color = create_color(
		game_data->floor_and_ceiling.floor.r,
		game_data->floor_and_ceiling.floor.g,
		game_data->floor_and_ceiling.floor.b);
	y = ray->draw_end;
	while (y < game_data->mlx_data.win_height)
	{
		*((unsigned int *)(img->pixel_info + y * img->line_length + x
			* (img->bpp / 8))) = color;
		++y;
	}
}

void	draw_vertical_line(t_game_data *game_data, t_image_data *img, int x, t_ray *ray)
{
	draw_sky(game_data, img, ray, x);
	draw_wall(game_data, img, ray, x);
	draw_floor(game_data, img, ray, x);
}
