/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_escape_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:37:03 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/22 18:37:20 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

int	on_key_press(int keycode, void *param)
{
	if (keycode == ESC_KEY)
		on_close_window(param);
	return (EXIT_SUCCESS);
}
