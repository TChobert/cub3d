/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:18:34 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/02 19:11:03 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static t_color_values	*get_color_field(t_colors *colors,
	t_color_type color_type)
{
	if (color_type == FLOOR)
		return (&colors->floor);
	else
		return (&colors->ceiling);
}

static char	*get_color_values_begining(char *color)
{
	while (ft_isspace(*color) && *color != '\0')
	{
		++color;
	}
	return (color);
}

static t_color_status	save_color(t_parse_data *parse_data, const char *color,
							t_color_type color_type)
{
	const char		*color_values_begining
		= get_color_values_begining((char *)color + 2);
	t_color_values	*color_field;

	if (is_valid_color_string(color_values_begining) == INVALID_COLOR)
	{
		save_error_type(INVALID_COLOR_FORMAT, parse_data);
		return (INVALID_COLOR);
	}
	color_field = get_color_field(&parse_data->colors, color_type);
	if (color_field->is_full == true)
	{
		save_error_type(DOUBLE_ELEMENT, parse_data);
		return (INVALID_COLOR);
	}
	return (get_color_values(parse_data, color_values_begining, color_field));
}

t_color_status	get_color(t_parse_data *parse_data, const char *color,
					t_color_element *color_type)
{
	return (save_color(parse_data, color, color_type->type));
}
