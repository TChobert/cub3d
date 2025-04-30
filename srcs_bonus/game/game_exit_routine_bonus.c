/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_routine_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:51:55 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:12:30 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

static void	destroy_mlx_elements(t_mlx_data *mlx_data)
{
	if (mlx_data->win_ptr != NULL)
		mlx_destroy_window(mlx_data->mlx_ptr,
			mlx_data->win_ptr);
	if (mlx_data->mlx_ptr != NULL)
	{
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
	}
}

static void	destroy_images(t_mlx_data *mlx_data, t_images_data *images)
{
	if (images->north_texture_img.img_ptr != NULL)
		mlx_destroy_image(mlx_data->mlx_ptr, images->north_texture_img.img_ptr);
	if (images->south_texture_img.img_ptr != NULL)
		mlx_destroy_image(mlx_data->mlx_ptr, images->south_texture_img.img_ptr);
	if (images->east_texture_img.img_ptr != NULL)
		mlx_destroy_image(mlx_data->mlx_ptr, images->east_texture_img.img_ptr);
	if (images->west_texture_img.img_ptr != NULL)
		mlx_destroy_image(mlx_data->mlx_ptr, images->west_texture_img.img_ptr);
	if (mlx_data->frame_img.img_ptr != NULL)
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->frame_img.img_ptr);
}

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
	destroy_images(&game_data->mlx_data, &game_data->images);
	destroy_mlx_elements(&game_data->mlx_data);
}
