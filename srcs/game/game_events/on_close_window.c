/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:46:25 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/22 17:46:38 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

int	on_close_window(void *param)
{
	t_game_data	*game_data;

	game_data = (t_game_data *)param;
	game_exit_routine(game_data);
	exit(SUCCESS);
	return (EXIT_SUCCESS);
}
