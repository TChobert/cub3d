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

	if (map_x < 0.98 || map_y < 0.98 || map_x >= (map_length - 1.2)
		|| map_y >= (map_width - 1.2))
		return (false);
	return (true);
}

static bool	is_in_wall(t_game_data *game_data, int x, int y)
{
	if (game_data->map.map[y][x] == '1')
		return (true);
	return (false);
}

static bool	is_near_wall(t_game_data *game_data, double new_x, double new_y,
				double tolerance)
{
	double	i;
	double	j;
	int		check_x;
	int		check_y;

	i = -tolerance;
	while (i <= tolerance)
	{
		j = -tolerance;
		while (j <= tolerance)
		{
			check_x = (int)(new_x + i);
			check_y = (int)(new_y + j);
			if (check_x >= 0 && check_x < (int)game_data->map.map_length
				&& check_y >= 0 && check_y < (int)game_data->map.map_width)
			{
				if (is_in_wall(game_data, check_x, check_y))
					return (true);
			}
			j += 0.05;
		}
		i += 0.05;
	}
	return (false);
}

static bool	is_not_in_wall(t_game_data *game_data, double new_x,
				double new_y)
{
	const int		map_x = (int)new_x;
	const int		map_y = (int)new_y;
	const double	tolerance = 0.17;

	if (is_in_wall(game_data, map_x, map_y))
		return (false);
	if (is_near_wall(game_data, new_x, new_y, tolerance))
		return (false);
	return (true);
}

bool	is_valid_move(t_game_data *game_data, double new_x,
			double new_y)
{
	if (is_in_map(game_data, new_x, new_y) == false)
		return (false);
	return (is_not_in_wall(game_data, new_x, new_y));
}
