/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:43:24 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/01 16:48:22 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static t_texture	*get_texture_field(t_textures *textures,
						t_texture_type texture_type)
{
	if (texture_type == NORTH)
		return (&textures->north_texture);
	else if (texture_type == SOUTH)
		return (&textures->south_texture);
	else if (texture_type == EAST)
		return (&textures->east_texture);
	else
		return (&textures->west_texture);
}

static bool	is_not_only_a_path(const char *path)
{
	return (ft_count_words(path, ' ') > 1);
}

static char	*format_texture_path(t_game_data *game_data, const char *texture)
{
	char	*formatted_texture_path;

	formatted_texture_path = ft_strtrim(texture + 3, WHITESPACES);
	if (formatted_texture_path == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\nMalloc failure in format_texture.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	return (formatted_texture_path);
}

static t_texture_status	save_texture(t_game_data *game_data,
							const char *texture, t_texture_type texture_type)
{
	char		*texture_path_to_save;
	t_texture	*texture_field;

	texture_path_to_save = format_texture_path(game_data, texture);
	if (is_not_only_a_path(texture_path_to_save) == true)
	{
		save_error_type(INVALID_ID, game_data);
		game_data->textures.is_invalid_texture = true;
		return (INVALID_TEXTURE);
	}
	texture_field = get_texture_field(&game_data->textures, texture_type);
	if (*texture_field != NULL)
	{
		save_error_type(DOUBLE_ELEMENT, game_data);
		game_data->textures.is_invalid_texture = true;
		return (INVALID_TEXTURE);
	}
	*texture_field = texture_path_to_save;
	return (VALID_TEXTURE);
}

t_texture_status	get_texture(t_game_data *game_data,
						const char *texture, t_texture_element *texture_type)
{
	if (is_valid_texture_prefix(texture, texture_type->id) == false)
	{
		save_error_type(INVALID_ID, game_data);
		game_data->textures.is_invalid_texture = true;
		return (INVALID_TEXTURE);
	}
	if (is_valid_xpm_path(game_data, texture + 3) == false)
	{
		save_error_type(INVALID_XPM, game_data);
		game_data->textures.is_invalid_texture = true;
		return (INVALID_TEXTURE);
	}
	return (save_texture(game_data, texture, texture_type->type));
}
