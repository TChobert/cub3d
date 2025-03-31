/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:43:24 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/28 18:30:48 by racoutte         ###   ########.fr       */
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

static void	save_texture(t_game_data *game_data, const char *texture,
				t_texture_type texture_type)
{
	t_texture	*texture_field;

	texture_field = get_texture_field(&game_data->textures, texture_type);
	*texture_field = ft_strdup(texture);
	if (texture_field == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\n"
			"Malloc failure during save_texture.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
}

t_texture_status	get_texture(t_game_data *game_data,
						const char *texture, t_texture_element *texture_type)
{
	if (is_valid_texture_prefix(texture, texture_type->id) == false)
	{
		return (INVALID_TEXTURE);
	}
	if (is_valid_xpm_path(texture + 3) == false)
		return (INVALID_TEXTURE);
	save_texture(game_data, texture, texture_type->type);
	return (VALID_TEXTURE);
}

// ligne 34 verif si deja plein