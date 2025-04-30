/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_dda_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:37:09 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:12:16 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

void	launch_dda(t_game_data *game_data, t_ray *ray)
{
	bool	hit;
	int		side;

	hit = false;
	side = -1;
	while (hit == false)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step_x;
			side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step_y;
			side = 1;
		}
		if (game_data->map.map[ray->map.y][ray->map.x] == '1')
			hit = true;
	}
	ray->side = side;
}
