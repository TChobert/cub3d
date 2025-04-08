/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_walls_characters.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:46 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/07 16:58:02 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static bool	is_valid_wall_character(char c)
{
	return (c == '1' || ft_isspace(c));
}

static bool	is_valid_wall_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (is_valid_wall_character(line[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

t_map_status	check_if_valid_first_and_last_wall_line(t_map_data *map_data)
{
	if (is_valid_wall_line(map_data->map_array[0]) == false
		|| is_valid_wall_line(
			map_data->map_array[map_data->map_lines_number - 1]) == false)
		return (INVALID_MAP);
	return (VALID_MAP);
}
