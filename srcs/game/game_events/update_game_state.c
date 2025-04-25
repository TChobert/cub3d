/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:40:10 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/25 15:40:23 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

int	update_game_state(t_game_data *game_data)
{
	return (move_character(game_data));
}
