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
	printf("C R ==== %d\n", game_data.colors.ceiling.R);
	printf("F R  ==== %d\n", game_data.colors.floor.R);
	printf("C G ==== %d\n", game_data.colors.ceiling.G);
	printf("F G  ==== %d\n", game_data.colors.floor.G);
	printf("C B ==== %d\n", game_data.colors.ceiling.B);
	printf("F B  ==== %d\n", game_data.colors.floor.B);
	printf("End of parsing reached\n");
	parser_exit_routine(&game_data);
	return (PARSE_SUCCESS);
}
