/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:00:48 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/28 18:40:22 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_parsing_status	parsing(char *map_file_path)
{
	t_game_data	game_data;

	ft_bzero(&game_data, sizeof(game_data));
	if (map_file_opener(map_file_path, &game_data.file_fd) == INVALID_MAP_FILE)
		return (PARSE_ERROR);
	if (parse_map_file(&game_data) == INVALID_CONTENT)
		return (PARSE_ERROR);
	printf("End of parsing reached\n");
	// test
	printf("NO = %s\n", game_data.textures.north_texture);
	printf("SO = %s\n", game_data.textures.south_texture);
	printf("WE = %s\n", game_data.textures.west_texture);
	printf("EA = %s\n", game_data.textures.east_texture);
	ft_free_and_null(game_data.map_file_content);
	free(game_data.textures.east_texture);
	free(game_data.textures.north_texture);
	free(game_data.textures.south_texture);
	free(game_data.textures.west_texture);
	return (PARSE_SUCCESS);
}
