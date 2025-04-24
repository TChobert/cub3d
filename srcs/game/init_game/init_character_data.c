/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_character_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:45:13 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/23 15:45:24 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

static void	setup_west_orientation(t_game_data *game_data)
{
	game_data->character.direction.x = -1;
	game_data->character.direction.y = 0;
	game_data->character.plane.x = 0;
	game_data->character.plane.y = -0.66;
}

static void	setup_east_orientation(t_game_data *game_data)
{
	game_data->character.direction.x = 1;
	game_data->character.direction.y = 0;
	game_data->character.plane.x = 0;
	game_data->character.plane.y = 0.66;
}

static void	setup_south_orientation(t_game_data *game_data)
{
	game_data->character.direction.x = 0;
	game_data->character.direction.y = 1;
	game_data->character.plane.x = -0.66;
	game_data->character.plane.y = 0;
}

static void	setup_north_orientation(t_game_data *game_data)
{
	game_data->character.direction.x = 0;
	game_data->character.direction.y = -1;
	game_data->character.plane.x = 0.66;
	game_data->character.plane.y = 0;
}

void	init_character_data(t_game_data *game_data)
{
	if (game_data->character.orientation == 'N')
		setup_north_orientation(game_data);
	else if (game_data->character.orientation == 'S')
		setup_south_orientation(game_data);
	else if (game_data->character.orientation == 'E')
		setup_east_orientation(game_data);
	else if (game_data->character.orientation == 'W')
		setup_west_orientation(game_data);
}
