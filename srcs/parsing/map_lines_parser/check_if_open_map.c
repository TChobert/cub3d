/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_open_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:32:48 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/09 16:05:48 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static bool	is_line_end_open(const char *map_line)
{
	size_t	line_end;

	line_end = ft_strlen(map_line) - 1;
	while (map_line[line_end] == ' ')
		line_end--;
	if (line_end == 0)
		return (true);
	return (map_line[line_end] != '1');
}

static bool	is_line_start_open(const char *map_line)
{
	size_t	i;

	i = 0;
	while (map_line[i] == ' ')
		i++;
	if (map_line[i] == '\0')
		return (true);
	return (map_line[i] != '1');
}

static t_map_status	is_open_map_line(const char *map_line)
{
	if (is_line_end_open(map_line) == true
		|| is_line_start_open(map_line) == true)
		return (INVALID_MAP);
	return (VALID_MAP);
}

t_map_status	check_if_open_map(t_parse_map_data *map)
{
	size_t	i;

	i = 0;
	while (i < map->map_lines_number)
	{
		if (is_empty_line(map->map_array[i]) == true)
		{
			ft_dprintf(STDERR_FILENO, "Error\nMap line %d is empty.\n",
				i + 1);
			return (INVALID_MAP);
		}
		else if (is_open_map_line(map->map_array[i]) == true)
		{
			ft_dprintf(STDERR_FILENO, "Error\nInvalid map at line %d.\n",
				i + 1);
			return (INVALID_MAP);
		}
		++i;
	}
	return (VALID_MAP);
}
