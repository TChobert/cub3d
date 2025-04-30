/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_map_parser_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:24:30 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:10:04 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

t_map_status	core_map_parser(t_parse_map_data *map)
{
	if (check_if_open_map(map) == INVALID_MAP)
	{
		return (INVALID_MAP);
	}
	if (check_if_invalid_core_map(map) == INVALID_MAP)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid map, please try again.\n");
		return (INVALID_MAP);
	}
	if (is_valid_number_of_characters(map->characters_number) == false)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid number of characters"
			" in map.\n");
		return (INVALID_MAP);
	}
	return (VALID_MAP);
}
