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

static void	display_map_absence(void)
{
	ft_dprintf(STDERR_FILENO, "Error\nNo map found.\n");
}

static void	check_if_no_map(t_game_data *game_data, size_t map_size)
{
	if (map_size == 0)
	{
		display_map_absence();
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
}

static void	fill_map_array(t_game_data *game_data, char **map_array, size_t	map_size)
{
	size_t	i;

	i = 0;
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
	size_t	map_size;

	map_size = game_data->map_file_lines_number - game_data->current_line;
	check_if_no_map(game_data, map_size);
	map_array = (char **)malloc(sizeof(char *) * (map_size + 1));
	if (map_array == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\nMalloc failure during function get_map.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	map_array[game_data->map_file_lines_number - game_data->current_line] = NULL;
	fill_map_array(game_data, map_array, map_size);
	game_data->game_map.map_array = map_array;
	return (VALID_MAP);
}
