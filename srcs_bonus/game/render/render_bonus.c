/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:45:38 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 14:33:35 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

int	render(t_game_data *game_data)
{
	raycast(game_data);
	draw_minimap(game_data);
	draw_frame_to_window(game_data);
	return (SUCCESS);
}
