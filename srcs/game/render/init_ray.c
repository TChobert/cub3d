/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:11:28 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/25 16:11:37 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

void	init_ray(t_game_data *game_data, t_ray *ray, size_t	x)
{
	double	camera_x;

	ray->map.x = (int)game_data->character.position.x;
	ray->map.y = (int)game_data->character.position.y;
	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir.x = game_data->character.direction.x
		+ game_data->character.plane.x * camera_x;
	ray->ray_dir.y = game_data->character.direction.y
		+ game_data->character.plane.y * camera_x;
}
