/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:00:48 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/25 17:21:05 by racoutte         ###   ########.fr       */
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
	ft_free_and_null(game_data.map_file_data);
	return (PARSE_SUCCESS);
}
