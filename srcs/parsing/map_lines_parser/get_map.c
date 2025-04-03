/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:35:47 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/03 16:36:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static void	fill_map_array(t_game_data *game_data, char **map_array)
{
	size_t	i;
	size_t	map_size;

	i = 0;
	map_size = game_data->map_file_lines_number - game_data->current_line;
	while (i < map_size)
	{
		map_array[i] = ft_strdup(game_data->map_file_content[game_data->current_line + i]);
		if (map_array[i] == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Error\nMalloc failure during function fill_map_array.\n");
			parser_exit_routine(game_data);
			exit(FAILURE);
		}
		++i;
	}
}

t_map_status	get_map(t_game_data *game_data)
{
	char	**map_array;

	map_array = (char **)malloc(sizeof(char *) * (game_data->map_file_lines_number - game_data->current_line));
	if (map_array == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\nMalloc failure during function get_map.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	map_array[game_data->map_file_lines_number - game_data->current_line] = NULL;
	fill_map_array(game_data, map_array);
	game_data->game_map.map_array = map_array;
	return (VALID_MAP);
}
