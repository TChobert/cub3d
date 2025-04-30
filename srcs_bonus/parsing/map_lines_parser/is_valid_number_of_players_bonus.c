/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number_of_players_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:04:43 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:10:19 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

bool	is_valid_number_of_characters(size_t characters_number)
{
	if (characters_number != 1)
	{
		return (false);
	}
	return (true);
}
