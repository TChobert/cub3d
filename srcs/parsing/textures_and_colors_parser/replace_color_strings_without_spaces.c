/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_color_strings_without_spaces.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:16:58 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/02 14:50:31 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static t_color	ft_strcpy_color_without_spaces(t_color src, t_color dest)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j])
	{
		if (!ft_isspace(src[j]))
		{
			dest[i] = src[j];
			++i;
		}
		++j;
	}
	dest[i] = '\0';
	return (dest);
}

static t_color	get_color_string_without_spaces(t_color color_string, t_game_data *game_data)
{
	t_color	color_string_without_spaces;

	if (!color_string)
		return (NULL);
	color_string_without_spaces = malloc(sizeof(char) * (ft_strlen(color_string) + 1));
	if (!color_string_without_spaces)
	{
		ft_dprintf(STDERR_FILENO, "Error\n"
			"Malloc failure during function get_color_without_spaces.\n");
		parser_exit_routine(game_data); //free color_string ?
		exit(FAILURE);
	}
	ft_strcpy_color_without_spaces(color_string, color_string_without_spaces);
	return (color_string_without_spaces);
}

void	replace_color_strings_without_spaces(t_game_data *game_data)
{
	t_color	temp;

	if (game_data->colors.floor_color)
	{
		temp = get_color_string_without_spaces(game_data->colors.floor_color, game_data);
		free(game_data->colors.floor_color);
		game_data->colors.floor_color = temp;
	}
	if (game_data->colors.ceiling_color)
	{
		temp = get_color_string_without_spaces(game_data->colors.ceiling_color, game_data);
		free(game_data->colors.ceiling_color);
		game_data->colors.ceiling_color = temp;
	}
}
