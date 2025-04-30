/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_characters_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:14:30 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:10:25 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

bool	is_valid_player_character(char c)
{
	return (ft_strchr(VALID_PLAYER_CHAR, c) != NULL);
}

static bool	is_valid_map_character(char c)
{
	return (c == '0' || c == '1'
		|| is_valid_player_character(c) || c == ' ');
}

t_map_status	check_if_valid_map_characters(t_parse_map_data *map_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map_data->map_array[i])
	{
		j = 0;
		while (map_data->map_array[i][j])
		{
			if (is_valid_map_character(map_data->map_array[i][j]) == false)
				return (INVALID_MAP);
			++j;
		}
		++i;
	}
	return (VALID_MAP);
}
