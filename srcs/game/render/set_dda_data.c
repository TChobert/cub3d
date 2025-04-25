/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dda_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:19:16 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/25 16:19:25 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

static void	set_ray_dir_x(t_game_data *game_data, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (game_data->character.position.x
			- ray->map.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map.x + 1.0
			- game_data->character.position.x)
			* ray->delta_dist.x;
	}
}

static void	set_ray_dir_y(t_game_data *game_data, t_ray *ray)
{
	if (ray->ray_dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y
			= (game_data->character.position.y - ray->map.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y
			= (ray->map.y + 1.0 - game_data->character.position.y)
			* ray->delta_dist.y;
	}
}

void	set_dda_data(t_game_data *game_data, t_ray *ray)
{
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	set_ray_dir_x(game_data, ray);
	set_ray_dir_y(game_data, ray);
}
