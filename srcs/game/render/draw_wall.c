/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-28 09:48:04 by tchobert          #+#    #+#             */
/*   Updated: 2025-04-28 09:48:04 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

static int	calculate_tex_x(t_game_data *game_data, t_ray *ray, t_image_data *texture)
{
	double	wall_x;
	int		tex_x;

	if(ray->side == 0)
	{
		wall_x = game_data->character.position.y + ray->perp_wall_dist * ray->ray_dir.y;
	}
	else
	{
		wall_x = game_data->character.position.x + ray->perp_wall_dist * ray->ray_dir.x;
	}
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)(texture->width));
	if ((ray->side == 0 && ray->ray_dir.x > 0) || (ray->side == 1 && ray->ray_dir.y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

static int	calculate_tex_y(t_ray *ray, t_image_data *texture, int y)
{
	return ((int)( (y - ray->draw_start) * texture->height / ray->line_height ));
}

static unsigned int	*get_pixel_color(t_image_data *texture, int tex_x, int tex_y)
{
	return (((unsigned int *)(texture->pixel_info + tex_y * texture->line_length + tex_x * (texture->bpp / 8))));
}

void	put_pixel(t_image_data *img, int x, int y, unsigned int color)
{
	*((unsigned int *)(img->pixel_info + y * img->line_length + x * (img->bpp / 8))) = color;
}

void	draw_wall(t_game_data *game_data, t_image_data *img, t_ray *ray,
			int x)
{
	t_image_data	*texture;
	int				tex_x;
	int				tex_y;
	int				y;
	unsigned int	color;

	texture = choose_texture(game_data, ray);
	tex_x = calculate_tex_x(game_data, ray, texture);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = calculate_tex_y(ray, texture, y);
		color = *(get_pixel_color(texture, tex_x, tex_y));
		put_pixel(img, x, y, color);
		++y;
	}
}
