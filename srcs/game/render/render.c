/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:45:38 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/25 15:45:53 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

int	render(t_game_data *game_data)
{
	raycast(game_data);
	draw_frame_to_window(game_data);
	return (SUCCESS);
}
