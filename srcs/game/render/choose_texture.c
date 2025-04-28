/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:33:51 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/28 11:34:03 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

t_image_data	*choose_texture(t_game_data *game_data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x == -1)
			return (&game_data->images.west_texture_img);
		else
			return (&game_data->images.east_texture_img);
	}
	else
	{
		if (ray->step_y == -1)
			return (&game_data->images.north_texture_img);
		else
			return (&game_data->images.south_texture_img);
	}
}
