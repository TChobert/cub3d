/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:28:17 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/11 19:41:08 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

static void	error_malloc_transfer_textures(t_game_data *game_data,
			t_parse_data *parse_data)
{
	ft_dprintf(STDERR_FILENO, "Error\nStrdup failed transfer_textures.\n");
	parser_exit_routine(parse_data);
	game_exit_routine(game_data);
}

static char	*get_texture_path(t_texture_type texture_type,
				t_parse_data *parse_data)
{
	if (texture_type == NORTH)
		return (parse_data->textures.north_texture);
	else if (texture_type == SOUTH)
		return (parse_data->textures.south_texture);
	else if (texture_type == EAST)
		return (parse_data->textures.east_texture);
	else if (texture_type == WEST)
		return (parse_data->textures.west_texture);
	return (NULL);
}

static char	**get_img_path_ptr(t_texture_type texture_type,
				t_game_data *game_data)
{
	if (texture_type == NORTH)
		return (&game_data->images.north_texture_img.img_path);
	else if (texture_type == SOUTH)
		return (&game_data->images.south_texture_img.img_path);
	else if (texture_type == EAST)
		return (&game_data->images.east_texture_img.img_path);
	else if (texture_type == WEST)
		return (&game_data->images.west_texture_img.img_path);
	return (NULL);
}

static void	copy_texture(t_texture_type texture_type, t_game_data *game_data,
				t_parse_data *parse_data)
{
	char	*source_path;
	char	**dest_path;

	source_path = get_texture_path(texture_type, parse_data);
	dest_path = get_img_path_ptr(texture_type, game_data);
	if (source_path == NULL || dest_path == NULL)
	{
		error_malloc_transfer_textures(game_data, parse_data);
		exit(FAILURE);
	}
	*dest_path = ft_strdup(source_path);
	if (*dest_path == NULL)
	{
		error_malloc_transfer_textures(game_data, parse_data);
		exit(FAILURE);
	}
}

void	transfer_textures(t_game_data *game_data, t_parse_data *parse_data)
{
	copy_texture(NORTH, game_data, parse_data);
	copy_texture(SOUTH, game_data, parse_data);
	copy_texture(EAST, game_data, parse_data);
	copy_texture(WEST, game_data, parse_data);
}
