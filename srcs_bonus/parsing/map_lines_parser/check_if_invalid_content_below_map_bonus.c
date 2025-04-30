/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_invalid_content_below_map_bonus.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:55:15 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:09:41 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

static size_t	find_last_full_line_in_file(t_parse_data *parse_data)
{
	size_t	i;

	i = parse_data->map_file_lines_number - 1;
	while (i > parse_data->current_line)
	{
		if (parse_data->map_file_content[i] != NULL
			&& !is_empty_line(parse_data->map_file_content[i]))
			return (i);
		i--;
	}
	return (parse_data->current_line);
}

void	check_if_invalid_content_below_map(t_parse_data *parse_data)
{
	size_t	last_full_line_index;

	last_full_line_index = find_last_full_line_in_file(parse_data);
	if (is_map_last_line(
			parse_data->map_file_content[last_full_line_index]) == false)
	{
		ft_dprintf(STDERR_FILENO,
			"Error\nInvalid content detected.\n");
		parser_exit_routine(parse_data);
		exit(FAILURE);
	}
}
