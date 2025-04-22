/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:08:12 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/24 14:33:34 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

void	run_game(t_game_data *game_data)
{
	(void)game_data;
	init_game(game_data);
	printf("Game part reached\n");
}
