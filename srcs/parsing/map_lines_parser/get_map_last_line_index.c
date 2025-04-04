/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_last_line_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:59:22 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/04 17:03:25 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

bool	is_map_last_line(const char *line)
{
	size_t	i;

	if (ft_strchr(line, '1') == NULL)
		return (false);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && ft_isspace(line[i]) == false)
			return (false);
		++i;
	}
	return (true);
}

size_t	get_map_last_line_index(t_game_data *game_data,
					char **map_file_last_part)
{
	size_t	i;

	i = ((game_data->map_file_lines_number - game_data->current_line) - 1);
	while (i > 0)
	{
		if (is_map_last_line(map_file_last_part[i]))
			return (i);
		--i;
	}
	return (0);
}
