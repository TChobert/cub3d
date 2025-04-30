/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:35:47 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:10:07 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

static char	**extract_map(t_parse_data *parse_data, char **map_file_last_part)
{
	char	**map;
	size_t	last_line_index;

	last_line_index
		= (get_map_last_line_index(parse_data, map_file_last_part) + 1);
	if (last_line_index == 1)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid map.\n");
		exit(FAILURE);
	}
	map = copy_map(map_file_last_part, last_line_index);
	parse_data->game_map.map_lines_number = last_line_index;
	if (map == NULL)
	{
		parser_exit_routine(parse_data);
		exit(FAILURE);
	}
	return (map);
}

t_map_status	get_map(t_parse_data *parse_data)
{
	char	**map;
	char	**map_array;
	char	**map_part;

	map_part = get_map_part(parse_data);
	map = extract_map(parse_data, map_part);
	map_array = build_map_array(parse_data, map);
	parse_data->game_map.map_array = map_array;
	ft_free_and_null(map_part);
	ft_free_and_null(map);
	return (VALID_MAP);
}
