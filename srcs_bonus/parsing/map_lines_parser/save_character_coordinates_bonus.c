/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_character_coordinates_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:03:56 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:10:22 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

void	save_character_coordinates(t_character_data *character_data,
				size_t i, size_t j)
{
	character_data->character_coords[COORD_Y] = i + 0.5;
	character_data->character_coords[COORD_X] = j + 0.5;
}
