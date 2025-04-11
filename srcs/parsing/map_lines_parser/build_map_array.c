/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:08:48 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/10 16:09:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

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

static void	fill_map_array_line(char *map_array_line, const char *map_line,
				size_t map_width)
{
	size_t	i;

	i = 0;
	while (i < map_width)
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

static int	fill_map_array(char **map_array, char **map, size_t map_length,
				size_t map_width)
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

char	**build_map_array(t_parse_data *parse_data, char **map)
{
	const size_t	map_length = parse_data->game_map.map_lines_number;
	char			**map_array;
	size_t			map_width;

	map_width = get_map_width(map);
	map_array = (char **)malloc(sizeof(char *) * (map_length + 1));
	if (map_array == NULL)
	{
		parser_exit_routine(parse_data);
		exit(FAILURE);
	}
	map_array[map_length] = NULL;
	if (fill_map_array(map_array, map, map_length, map_width) == FAILURE)
	{
		parser_exit_routine(parse_data);
		exit(FAILURE);
	}
	return (map_array);
}
