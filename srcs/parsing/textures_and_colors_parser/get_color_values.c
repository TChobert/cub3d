/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:29:43 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/02 19:18:50 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static void	fill_rgb_field(t_color_values *color_field, int RGB_value,
					t_rgb rgb_id)
{
	if (rgb_id == RED)
		color_field->r = RGB_value;
	else if (rgb_id == GREEN)
		color_field->g = RGB_value;
	else
		color_field->b = RGB_value;
}

static t_color_status	save_rgb_value(t_color_values *color_field,
							char **rgb_values, t_rgb rgb_id)
{
	int	rgb_value;

	if (ft_strlen(rgb_values[rgb_id]) > 3)
		return (INVALID_COLOR);
	rgb_value = ft_atoi(rgb_values[rgb_id]);
	if (rgb_value < 0 || rgb_value > 255)
		return (INVALID_COLOR);
	fill_rgb_field(color_field, rgb_value, rgb_id);
	return (VALID_COLOR);
}

static t_color_status	extract_color_rgb_values(t_game_data *game_data,
							t_color_values *color_field,
								char *spaceless_color_values)
{
	char	**color_rgb_values;

	color_rgb_values = ft_split(spaceless_color_values, ',');
	free(spaceless_color_values);
	if (color_rgb_values == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\nMalloc failure during function"
			" extract_color_values.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	if (save_rgb_value(color_field, color_rgb_values, RED) == INVALID_COLOR
		|| save_rgb_value(color_field, color_rgb_values, GREEN) == INVALID_COLOR
		|| save_rgb_value(color_field, color_rgb_values, BLUE) == INVALID_COLOR)
	{
		ft_free_and_null(color_rgb_values);
		save_error_type(INVALID_RGB_VALUE, game_data);
		return (INVALID_COLOR);
	}
	color_field->is_full = true;
	ft_free_and_null(color_rgb_values);
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
	return (extract_color_rgb_values(game_data, color_field,
			spaceless_color_values));
}
