/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:54:51 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 17:55:02 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

static void rotate_view(t_game_data *game_data, double angle)
{
	const double old_dir_x = game_data->character.direction.x;
	const double old_plane_x = game_data->character.plane.x;

	game_data->character.direction.x = game_data->character.direction.x
		* cos(angle)
		- game_data->character.direction.y * sin(angle);
	game_data->character.direction.y = old_dir_x * sin(angle)
		+ game_data->character.direction.y * cos(angle);
	game_data->character.plane.x = game_data->character.plane.x * cos(angle)
		- game_data->character.plane.y * sin(angle);
	game_data->character.plane.y = old_plane_x * sin(angle)
		+ game_data->character.plane.y * cos(angle);
}

int	on_mouse_move(int x, int y, void *param)
{
	static int	last_x_value = -1;
	t_game_data	*game_data;
	double		sensitivity;
	double		angle;
	int			delta_x;

	(void)y;
	game_data = (t_game_data *)param;
	if (last_x_value == -1)
		last_x_value = x;
	delta_x = x - last_x_value;
	last_x_value = x;
	sensitivity = 0.003f;
	angle = delta_x * sensitivity;
	rotate_view(game_data, angle);
	return (SUCCESS);
}
