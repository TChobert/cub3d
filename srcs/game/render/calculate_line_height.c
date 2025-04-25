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

static void	calculate_wall_distance(t_game_data *game_data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map.x - game_data->character.position.x
			+ (1 - ray->step_x) / 2) / ray->ray_dir.x;
	else
		ray->perp_wall_dist = (ray->map.y - game_data->character.position.y
			+ (1 - ray->step_y) / 2) / ray->ray_dir.y;
}

void	calculate_line_height(t_game_data *game_data, t_ray *ray)
{
	int	line_height;

	calculate_wall_distance(game_data, ray);
	line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	
}
