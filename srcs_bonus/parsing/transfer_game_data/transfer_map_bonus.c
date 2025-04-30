/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:25:06 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:08:22 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game_bonus.h"

static void	replace_spaces_in_map_line(char *map_line)
{
	size_t	i;

	i = 0;
	while (map_line[i] != '\0')
	{
		if (map_line[i] == ' ')
			map_line[i] = '1';
		++i;
	}
}

static void	replace_spaces_in_map(char **map, size_t map_length)
{
	size_t	i;

	i = 0;
	while (i < map_length)
	{
		replace_spaces_in_map_line(map[i]);
		++i;
	}
}

int	transfer_map(t_game_data *game_data, t_parse_data *parse_data)
{
	char	**map;

	map = copy_map(parse_data->game_map.map_array,
			parse_data->game_map.map_lines_number);
	if (map == NULL)
	{
		return (FAILURE);
	}
	replace_spaces_in_map(map, parse_data->game_map.map_lines_number);
	game_data->map.map = map;
	game_data->map.map_width = parse_data->game_map.map_lines_number;
	game_data->map.map_length = ft_strlen(game_data->map.map[0]);
	return (SUCCESS);
}
