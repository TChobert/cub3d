/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:09:34 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/10 15:13:10 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_content_status	check_if_valid_map(t_map_data *map_data)
{
	if (check_if_valid_map_characters(map_data) == INVALID_MAP)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid character detected.\n");
		return (INVALID_CONTENT);
	}
	if (check_if_valid_first_and_last_wall_line(map_data) == INVALID_MAP)
	{
		ft_dprintf(STDERR_FILENO, "Error\nUnclosed map.\n");
		return (INVALID_CONTENT);
	}
	if (core_map_parser(map_data) == INVALID_MAP)
	{
		return (INVALID_CONTENT);
	}
	return (VALID_CONTENT);
}
