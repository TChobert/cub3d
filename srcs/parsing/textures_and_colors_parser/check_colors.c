/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:43:03 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/02 19:10:33 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static bool	is_color_missing(t_colors colors)
{
	if (colors.floor.is_full == false || colors.ceiling.is_full == false)
	{
		return (true);
	}
	return (false);
}

static bool	is_map_line(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == false && line[i] != ' ')
			return (false);
		++i;
	}
	return (true);
}

static void	display_colors_error_message(t_parse_data *parse_data)
{
	if (parse_data->parse_error_info.error_type == DOUBLE_ELEMENT)
	{
		ft_dprintf(STDERR_FILENO, "Error\n%s: is present twice.\n",
			parse_data->parse_error_info.invalid_element);
		parser_exit_routine(parse_data);
		exit(FAILURE);
	}
	else if (parse_data->parse_error_info.error_type == INVALID_ID)
	{
		if (is_map_line(parse_data->parse_error_info.invalid_element) == false)
		{
			ft_dprintf(STDERR_FILENO, "Error\n%s: invalid element.\n",
				parse_data->parse_error_info.invalid_element);
			parser_exit_routine(parse_data);
			exit(FAILURE);
		}
	}
	else if (parse_data->parse_error_info.error_type != NO_ERROR
		&& is_color_missing(parse_data->colors) == true)
	{
		ft_dprintf(STDERR_FILENO, "Error\n%s: invalid color.\n",
			parse_data->parse_error_info.invalid_element);
		parser_exit_routine(parse_data);
		exit(FAILURE);
	}
}

void	check_colors(t_parse_data *parse_data)
{
	display_colors_error_message(parse_data);
	if (is_color_missing(parse_data->colors) == true)
	{
		ft_dprintf(STDERR_FILENO, "Error\n4 textures paths and two colors"
			" in RGB format are required before any other information to "
			"start the game.\n");
		parser_exit_routine(parse_data);
		exit(FAILURE);
	}
}
