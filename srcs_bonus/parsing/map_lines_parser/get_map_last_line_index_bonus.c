/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_last_line_index_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:59:22 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:10:12 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

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

size_t	get_map_last_line_index(t_parse_data *parse_data,
					char **map_file_last_part)
{
	size_t	i;

	i = ((parse_data->map_file_lines_number - parse_data->current_line) - 1);
	while (i > 0)
	{
		if (is_map_last_line(map_file_last_part[i]))
			return (i);
		--i;
	}
	return (0);
}
