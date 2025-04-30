/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:14:09 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 15:33:41 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

static void	choose_color_minimap(char cell, unsigned int *color)
{
	if (cell == '1')
		*color = COLOR_BLACK;
	else
		*color = COLOR_LIGHT_GREY;
}

static void	put_pixel_minimap(t_game_data *game_data, t_minimap_data *minimap,
			t_map_coord map, unsigned int color)
{
	t_map_coord		pixel;
	int				i;
	int				j;

	i = 0;
	while (i < minimap->cell_size)
	{
		j = 0;
		while (j < minimap->cell_size)
		{
			pixel.x = minimap->offset.x + map.x * minimap->cell_size + j;
			pixel.y = minimap->offset.y + map.y * minimap->cell_size + i;
			put_pixel(&game_data->mlx_data.frame_img, pixel.x, pixel.y, color);
			j++;
		}
		i++;
	}
}

static void	clear_minimap(t_game_data *game_data, t_minimap_data *minimap)
{
	t_map_coord		map;
	unsigned int	color;

	map.y = 0;
	color = COLOR_WHITE;
	while (map.y < (int)game_data->map.map_width)
	{
		map.x = 0;
		while (map.x < (int)game_data->map.map_length)
		{
			put_pixel_minimap(game_data, minimap, map, color);
			map.x++;
		}
		map.y++;
	}
}

static void	draw_minimap_background(t_game_data *game_data,
			t_minimap_data *minimap)
{
	t_map_coord		map;
	char			cell;
	unsigned int	color;

	map.y = 0;
	while (map.y < (int)game_data->map.map_width)
	{
		map.x = 0;
		while (map.x < (int)game_data->map.map_length)
		{
			cell = game_data->map.map[map.y][map.x];
			choose_color_minimap(cell, &color);
			put_pixel_minimap(game_data, minimap, map, color);
			map.x++;
		}
		map.y++;
	}
}

void	draw_minimap(t_game_data *game_data)
{
	t_minimap_data	minimap;

	minimap.cell_size = 5;
	minimap.offset.x = 10;
	minimap.offset.y = 10;
	clear_minimap(game_data, &minimap);
	draw_minimap_background(game_data, &minimap);
	draw_minimap_player(game_data, &minimap);
}
