/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:35:47 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/07 14:59:52 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static char	**copy_map(char **src, size_t map_size)
{
	char	**map;
	size_t	i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (map_size + 1));
	if (map == NULL)
	{
		ft_dprintf(STDERR_FILENO,
			"Error.\n Malloc failure during copy_map.\n");
		return (NULL);
	}
	map[map_size] = NULL;
	while (i < map_size)
	{
		map[i] = ft_strdup(src[i]);
		if (map[i] == NULL)
		{
			ft_dprintf(STDERR_FILENO,
				"Error\n Malloc failure during copy_map.\n");
			return (NULL);
		}
		++i;
	}
	return (map);
}

static char	**extract_map(t_game_data *game_data, char **map_file_last_part)
{
	char	**map;
	size_t	last_line_index;

	last_line_index
		= (get_map_last_line_index(game_data, map_file_last_part) + 1);
	if (last_line_index == 1)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid map.\n");
		exit(FAILURE);
	}
	map = copy_map(map_file_last_part, last_line_index);
	game_data->game_map.map_lines_number = last_line_index;
	if (map == NULL)
	{
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	return (map);
}

t_map_status	get_map(t_game_data *game_data)
{
	char	**map;
	char	**map_part;

	map_part = get_map_part(game_data);
	map = extract_map(game_data, map_part);
	game_data->game_map.map_array = map;
	ft_free_and_null(map_part);
	ft_display_strs_array(game_data->game_map.map_array, STDOUT_FILENO);
	return (VALID_MAP);
}
