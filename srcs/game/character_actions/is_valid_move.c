/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:06:48 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/28 14:06:59 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

static bool	is_in_map(t_game_data *game_data, double new_x, double new_y)
{
	const int	map_length = (int)game_data->map.map_length;
	const int	map_width = (int)game_data->map.map_width;
	const int	map_x = (int)new_x;
	const int	map_y = (int)new_y;

	if (map_x < 0 || map_y < 0 || map_x >= map_length - 1
		|| map_y >= map_width - 1)
		return (false);
	return (true);
}

static bool	is_not_in_wall(t_game_data *game_data, double new_x, double new_y)
{
	const int	map_x = (int)new_x;
	const int	map_y = (int)new_y;

	if (game_data->map.map[map_y][map_x] == '1')
		return (false);
	return (true);
}

bool is_valid_move(t_game_data *game_data, double new_x, double new_y)
{
	if (is_in_map(game_data, new_x, new_y) == false)
		return (false);
	return (is_not_in_wall(game_data, new_x, new_y));
}
