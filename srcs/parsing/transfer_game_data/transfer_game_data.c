/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_game_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:48:06 by tchobert          #+#    #+#             */
/*   Updated: 2025/05/01 17:44:22 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

// void	print_game_data(t_game_data *game_data)
// {
// 	ft_display_strs_array(game_data->map.map, STDOUT_FILENO);
// 	printf("LENGTH = %zu\n", game_data->map.map_length);
// 	printf("WIDTH = %zu\n\n", game_data->map.map_width);
// 	printf("TEXTURES\nNORTH_TEXTURE = %s\n",
// 		game_data->images.north_texture_img.img_path);
// 	printf("EAST_TEXTURE = %s\n",
// 		game_data->images.east_texture_img.img_path);
// 	printf("WEST_TEXTURE = %s\n",
// 		game_data->images.west_texture_img.img_path);
// 	printf("SOUTH_TEXTURE = %s\n\n",
// 		game_data->images.south_texture_img.img_path);
// 	printf("COLORS\nFLOOR COLOR / R = %d / G = %d / B = %d\n",
// 		game_data->floor_and_ceiling.floor.r,
// 		game_data->floor_and_ceiling.floor.g,
// 		game_data->floor_and_ceiling.floor.b);
// 	printf("CEILING COLOR / R = %d / G = %d / B = %d\n\n",
// 		game_data->floor_and_ceiling.ceiling.r,
// 		game_data->floor_and_ceiling.ceiling.g,
// 		game_data->floor_and_ceiling.ceiling.b);
// 	printf("CHARACTER DATA\nPOSITION / X = %f / Y = %f\n",
// 		game_data->character.position.x,
// 		game_data->character.position.y);
// 	printf("ORIENTATION = %c\n\n", game_data->character.orientation);
// }

void	transfer_game_data(t_game_data *game_data, t_parse_data *parse_data)
{
	if (transfer_map(game_data, parse_data) == FAILURE)
	{
		ft_dprintf(STDERR_FILENO, "Error\nTransfer map failed.\n");
		parser_exit_routine(parse_data);
		game_exit_routine(game_data);
		exit(FAILURE);
	}
	transfer_textures(game_data, parse_data);
	transfer_colors(game_data, parse_data);
	transfer_character_data(game_data, parse_data);
}
