/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:51:55 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/11 18:56:28 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

static void	free_images_paths(t_images_data images)
{
	free(images.north_texture_img.img_path);
	free(images.south_texture_img.img_path);
	free(images.east_texture_img.img_path);
	free(images.west_texture_img.img_path);
}

void	game_exit_routine(t_game_data *game_data)
{
	ft_free_and_null(game_data->map.map);
	free_images_paths(game_data->images);
}
