/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:29:43 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/02 15:29:58 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static void	fill_RGB_field(t_color_values *color_field, int RGB_value,
					t_RGB RGB_id)
{
	if (RGB_id == RED)
		color_field->R = RGB_value;
	else if (RGB_id == GREEN)
		color_field->G = RGB_value;
	else
		color_field->B = RGB_value;
}

static t_color_status	save_RGB_value(t_color_values *color_field, char **RGB_values,
							t_RGB RGB_id)
{
	int	RGB_value;

	if (ft_strlen(RGB_values[RGB_id]) > 3)
		return (INVALID_COLOR);
	RGB_value = ft_atoi(RGB_values[RGB_id]);
	if (RGB_value < 0)
		return (INVALID_COLOR);
	fill_RGB_field(color_field, RGB_value, RGB_id);
	return (VALID_COLOR);
}

static t_color_status	extract_color_RGB_values(t_game_data *game_data,
							t_color_values *color_field, char *spaceless_color_values)
{
	char	**color_RGB_values;

	color_RGB_values = ft_split(spaceless_color_values, ',');
	if(color_RGB_values == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\nMalloc failure during function"
			" extract_color_values.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	if (save_RGB_value(color_field, color_RGB_values, RED) == INVALID_COLOR
		|| save_RGB_value(color_field, color_RGB_values, GREEN) == INVALID_COLOR
		|| save_RGB_value(color_field, color_RGB_values, BLUE) == INVALID_COLOR)
	{
		return (INVALID_COLOR);
	}
	return (VALID_COLOR);
}

t_color_status	get_color_values(t_game_data *game_data,
					const char *color_values, t_color_values *color_field)
{
	char	*spaceless_color_values;
	spaceless_color_values = remove_spaces((char *)color_values);
	if (spaceless_color_values == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\nMalloc failure during function"
			" get_color_values.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	return (extract_color_RGB_values(game_data, color_field, spaceless_color_values));
}
