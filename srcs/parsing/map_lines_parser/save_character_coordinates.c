/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_character_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:03:56 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/11 13:04:07 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

void	save_character_coordinates(t_character_data *character_data,
				size_t i, size_t j)
{
	character_data->character_coords[COORD_Y] = i + 0.5;
	character_data->character_coords[COORD_X] = j + 0.5;
}
