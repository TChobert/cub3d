/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:40:49 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:11:46 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

static void	set_default_window_size(t_mlx_data *mlx)
{
	mlx->win_width = WIN_WIDTH;
	mlx->win_height = WIN_HEIGHT;
}

static int	load_texture(t_mlx_data *mlx_data, t_image_data *texture)
{
	texture->img_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			texture->img_path, &texture->width, &texture->height);
	if (texture->img_ptr == NULL)
		return (FAILURE);
	texture->pixel_info = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->line_length, &texture->endian);
	return (SUCCESS);
}

static int	load_game_textures(t_game_data *game_data)
{
	if (load_texture(&game_data->mlx_data,
			&game_data->images.north_texture_img) == FAILURE)
		return (FAILURE);
	if (load_texture(&game_data->mlx_data,
			&game_data->images.south_texture_img) == FAILURE)
		return (FAILURE);
	if (load_texture(&game_data->mlx_data,
			&game_data->images.east_texture_img) == FAILURE)
		return (FAILURE);
	if (load_texture(&game_data->mlx_data,
			&game_data->images.west_texture_img) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	load_frame_image(t_mlx_data *mlx_data)
{
	mlx_data->frame_img.width = mlx_data->win_width;
	mlx_data->frame_img.height = mlx_data->win_height;
	mlx_data->frame_img.img_ptr = mlx_new_image(
			mlx_data->mlx_ptr,
			mlx_data->frame_img.width,
			mlx_data->frame_img.height);
	if (mlx_data->frame_img.img_ptr == NULL)
		return (FAILURE);
	mlx_data->frame_img.pixel_info = mlx_get_data_addr(
			mlx_data->frame_img.img_ptr,
			&mlx_data->frame_img.bpp,
			&mlx_data->frame_img.line_length,
			&mlx_data->frame_img.endian);
	return (SUCCESS);
}

int	init_mlx_data(t_game_data *game_data)
{
	game_data->mlx_data.mlx_ptr = mlx_init();
	if (game_data->mlx_data.mlx_ptr == NULL)
		return (FAILURE);
	set_default_window_size(&game_data->mlx_data);
	if (load_game_textures(game_data) == FAILURE)
		return (FAILURE);
	if (load_frame_image(&game_data->mlx_data) == FAILURE)
		return (FAILURE);
	game_data->mlx_data.win_ptr = mlx_new_window(game_data->mlx_data.mlx_ptr,
			game_data->mlx_data.win_width, game_data->mlx_data.win_height,
			"Cub3D");
	if (game_data->mlx_data.win_ptr == NULL)
		return (FAILURE);
	return (SUCCESS);
}
