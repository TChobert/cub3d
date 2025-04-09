/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:35:47 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/07 16:55:11 by racoutte         ###   ########.fr       */
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

static size_t	get_map_width(char **map)
{
	size_t	width;
	size_t	i;

	width = 0;
	i = 0;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) > width)
			width = ft_strlen(map[i]);
		++i;
	}
	return (width);
}

static void	fill_map_array_line(char *map_array_line, const char *map_line, size_t map_width)
{
	size_t	i;

	i = 0;
	while(i < map_width)
	{
		map_array_line[i] = ' ';
		++i;
	}
	map_array_line[map_width] = '\0';
	i = 0;
	while (map_array_line[i] != '\0' && map_line[i] != '\0')
	{
		map_array_line[i] = map_line[i];
		++i;
	}
}

static int	fill_map_array(char **map_array, char **map, size_t map_length, size_t map_width)
{
	size_t	i;

	i = 0;
	while (i < map_length)
	{
		map_array[i] = (char *)malloc(sizeof(char *) * map_width + 1);
		if (map_array[i] == NULL)
		{
			ft_free_and_null(map_array);
			ft_free_and_null(map);
			return (FAILURE);
		}
		fill_map_array_line(map_array[i], map[i], map_width);
		++i;
	}
	return (SUCCESS);
}

static char	**build_map_array(t_game_data *game_data, char **map)
{
	const size_t	map_length = game_data->game_map.map_lines_number;
	char			**map_array;
	size_t			map_width;

	map_width = get_map_width(map);
	map_array = (char **)malloc(sizeof(char *) * (map_length) + 1);
	if (map_array == NULL)
	{
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	map_array[map_length] = NULL;
	if (fill_map_array(map_array, map, map_length, map_width) == FAILURE)
	{
		// free map_array ??
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	return (map_array);
}

t_map_status	get_map(t_game_data *game_data)
{
	char	**map;
	char	**map_array;
	char	**map_part;

	map_part = get_map_part(game_data);
	map = extract_map(game_data, map_part);
	map_array = build_map_array(game_data, map);
	game_data->game_map.map_array = map_array;
	ft_free_and_null(map_part);
	ft_free_and_null(map);
	ft_display_strs_array(game_data->game_map.map_array, STDOUT_FILENO);
	return (VALID_MAP);
}
