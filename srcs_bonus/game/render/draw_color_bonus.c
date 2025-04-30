/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:28:40 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:12:00 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

unsigned int	create_color(int r, int g, int b)
{
	return (((unsigned int)0xFF << 24) | (r << 16) | (g << 8) | b);
}
