/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_invalid_core_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:52:41 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/11 15:00:11 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static bool	check_relative_chars(const char *valid_chars_list, char **map,
					size_t i, size_t j)
{
	if (ft_strchr(valid_chars_list, map[i - 1][j]) == NULL)
		return (false);
	if (ft_strchr(valid_chars_list, map[i + 1][j]) == NULL)
		return (false);
	if (ft_strchr(valid_chars_list, map[i][j - 1]) == NULL)
		return (false);
	if (ft_strchr(valid_chars_list, map[i][j + 1]) == NULL)
		return (false);
	return (true);
}

static bool	is_invalid_core_character(t_map_data *map, const char c,
				size_t i, size_t j)
{
	if (c == ' ')
	{
		if (check_relative_chars(SPACE_VALID_CHARS,
				map->map_array, i, j) == false)
			return (true);
	}
	if (is_valid_player_character(c) == true)
	{
		if (check_relative_chars(PLAYER_VALID_CHARS,
				map->map_array, i, j) == false)
			return (true);
	}
	else if (c == '0')
	{
		if (check_relative_chars(ZERO_VALID_CHARS,
				map->map_array, i, j) == false)
			return (true);
	}
	else if (c == '1')
	{
		if (check_relative_chars(WALL_VALID_CHARS,
				map->map_array, i, j) == false)
			return (true);
	}
	return (false);
}

t_map_status	check_if_invalid_core_map(t_map_data *map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < map->map_lines_number - 1)
	{
		j = 1;
		while (j < ft_strlen(map->map_array[i]) - 1)
		{
			if (is_valid_player_character(map->map_array[i][j]) == true)
			{
				save_character_coordinates(&map->character_data, i, j);
				map->character_data.character_orientation
					= map->map_array[i][j];
				map->characters_number += 1;
			}
			if (is_invalid_core_character(map,
					map->map_array[i][j], i, j) == true)
				return (INVALID_MAP);
			++j;
		}
		++i;
	}
	return (VALID_MAP);
}
