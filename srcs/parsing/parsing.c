/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:00:48 by racoutte          #+#    #+#             */
/*   Updated: 2025/05/01 17:43:39 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

t_parsing_status	parse_game_input(t_game_data *game_data,
						char *map_file_path)
{
	t_parse_data	parse_data;

	ft_bzero(&parse_data, sizeof(parse_data));
	if (map_file_opener(map_file_path, &parse_data.file_fd) == INVALID_MAP_FILE)
	{
		parser_exit_routine(&parse_data);
		return (PARSE_ERROR);
	}
	if (parse_map_file(&parse_data) == INVALID_CONTENT)
	{
		parser_exit_routine(&parse_data);
		return (PARSE_ERROR);
	}
	transfer_game_data(game_data, &parse_data);
	parser_exit_routine(&parse_data);
	return (PARSE_SUCCESS);
}
