/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_part_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:57:49 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:10:16 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

static void	fill_last_part_array(t_parse_data *parse_data, char **map_array,
				size_t map_size)
{
	size_t	i;

	i = 0;
	while (i < map_size)
	{
		map_array[i] = ft_strdup(
				parse_data->map_file_content[parse_data->current_line + i]);
		if (map_array[i] == NULL)
		{
			ft_dprintf(STDERR_FILENO,
				"Error\nMalloc failure during function fill_map_array.\n");
			parser_exit_routine(parse_data);
			exit(FAILURE);
		}
		++i;
	}
}

char	**get_map_part(t_parse_data *parse_data)
{
	char	**map_part;
	size_t	map_part_size;

	map_part_size
		= parse_data->map_file_lines_number - parse_data->current_line;
	check_if_no_map(parse_data, map_part_size);
	check_if_invalid_content_below_map(parse_data);
	map_part = (char **)malloc(sizeof(char *) * (map_part_size + 1));
	if (map_part == NULL)
	{
		ft_dprintf(STDERR_FILENO,
			"Error\nMalloc failure during function get_map_file_last_part.\n");
		parser_exit_routine(parse_data);
		exit(FAILURE);
	}
	map_part[parse_data->map_file_lines_number
		- parse_data->current_line] = NULL;
	fill_last_part_array(parse_data, map_part, map_part_size);
	return (map_part);
}
