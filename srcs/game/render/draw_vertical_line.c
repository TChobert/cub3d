/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:01:26 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/25 18:01:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

static void	draw_sky(t_image_data *img, t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
	{
		*((unsigned int *)(img->pixel_info + y * img->line_length + x * (img->bpp / 8))) = 0x87CEEB;
		++y;
	}
}

static void	draw_wall(t_image_data *img, t_ray *ray, int x)
{
	int	y;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		*((unsigned int *)(img->pixel_info + y * img->line_length + x * (img->bpp / 8))) = 0x808080;
		++y;
	}
}

static void	draw_floor(t_image_data *img, t_ray *ray, int x)
{
	int	y;

	y = ray->draw_end;
	while (y < WIN_HEIGHT)
	{
		*((unsigned int *)(img->pixel_info + y * img->line_length + x * (img->bpp / 8))) = 0x228B22;
		++y;
	}
}

void	draw_vertical_line(t_image_data *img, int x, t_ray *ray)
{
	int y;

	y = 0;
	draw_sky(img, ray, x);
	draw_wall(img, ray, x);
	draw_floor(img, ray, x);
}
