/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_player_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:23:33 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 15:34:30 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

static t_map_coord	calculate_player_position_minimap(t_game_data *game_data,
						t_minimap_data *minimap)
{
	t_map_coord	player_pixel;

	player_pixel.x = (int)(game_data->character.position.x * minimap->cell_size)
		+ minimap->offset.x;
	player_pixel.y = (int)(game_data->character.position.y * minimap->cell_size)
		+ minimap->offset.y;
	return (player_pixel);
}

void	draw_minimap_player(t_game_data *game_data, t_minimap_data *minimap)
{
	t_map_coord		player_pixel;
	unsigned int	player_color;
	int				dx;
	int				dy;

	player_pixel = calculate_player_position_minimap(game_data, minimap);
	player_color = COLOR_RED;
	dy = 0;
	while (dy < minimap->cell_size)
	{
		dx = 0;
		while (dx < minimap->cell_size)
		{
			put_pixel(&game_data->mlx_data.frame_img,
				player_pixel.x + dx, player_pixel.y + dy, player_color);
			dx++;
		}
		dy++;
	}
}
