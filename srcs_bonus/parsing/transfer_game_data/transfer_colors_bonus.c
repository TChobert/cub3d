/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_colors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:28:38 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:08:15 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

void	copy_ceiling_colors(t_game_data *game_data, t_parse_data *parse_data)
{
	game_data->floor_and_ceiling.ceiling.r = parse_data->colors.ceiling.r;
	game_data->floor_and_ceiling.ceiling.g = parse_data->colors.ceiling.g;
	game_data->floor_and_ceiling.ceiling.b = parse_data->colors.ceiling.b;
}

void	copy_floor_colors(t_game_data *game_data, t_parse_data *parse_data)
{
	game_data->floor_and_ceiling.floor.r = parse_data->colors.floor.r;
	game_data->floor_and_ceiling.floor.g = parse_data->colors.floor.g;
	game_data->floor_and_ceiling.floor.b = parse_data->colors.floor.b;
}

void	transfer_colors(t_game_data *game_data, t_parse_data *parse_data)
{
	copy_floor_colors(game_data, parse_data);
	copy_ceiling_colors(game_data, parse_data);
}
