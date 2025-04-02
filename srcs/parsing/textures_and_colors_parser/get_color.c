/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:18:34 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/01 21:18:47 by tchobert         ###   ########.fr       */
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

static t_color_status	save_color(t_game_data *game_data, const char *color,
							t_color_type color_type)
{
	const char		*color_values_begining
		= get_color_values_begining((char *)color + 2);
	t_color_values	*color_field;

	color_field = get_color_field(&game_data->colors, color_type);
	if (color_field->R != 0)
	{
		save_error_type(DOUBLE_ELEMENT, game_data);
		return (INVALID_COLOR);
	}
	return (get_color_values(game_data, color_values_begining, color_field));
}

t_color_status	get_color(t_game_data *game_data, const char *color,
	t_color_element *color_type)
{
	// if (parse_La_str_de_merde == INVLAID_STR)
	// 	return (MERDE)
	return (save_color(game_data, color, color_type->type));
}
