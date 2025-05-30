/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_line_height.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:50:58 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/25 16:51:08 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

static void	calculate_draw_start(t_ray *ray)
{
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
}

static void	calculate_draw_end(t_ray *ray)
{
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

static void	calculate_wall_distance(t_game_data *game_data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map.x - game_data->character.position.x
				+ (1 - ray->step_x) / 2) / ray->ray_dir.x;
	else
		ray->perp_wall_dist = (ray->map.y - game_data->character.position.y
				+ (1 - ray->step_y) / 2) / ray->ray_dir.y;
	if (ray->perp_wall_dist < 0.05)
		ray->perp_wall_dist = 0.05;
}

void	calculate_line_height(t_game_data *game_data, t_ray *ray)
{
	int	line_height;

	calculate_wall_distance(game_data, ray);
	if (ray->perp_wall_dist < 0.1)
		ray->perp_wall_dist = 0.1;
	line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->line_height = line_height;
	calculate_draw_start(ray);
	calculate_draw_end(ray);
}
