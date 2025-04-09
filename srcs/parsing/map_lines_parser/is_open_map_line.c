/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_open_map_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:32:48 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/09 12:32:51 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static bool	is_line_end_open(const char *map_line)
{
	int	line_end;

	line_end = ft_strlen(map_line) - 1;
	while (line_end >= 0 && map_line[line_end] == ' ')
		line_end--;
	if (line_end < 0)
		return (true);
	return (map_line[line_end] != '1');
}

static bool	is_line_start_open(const char *map_line)
{
	int	i = 0;
	while (map_line[i] && map_line[i] == ' ')
		i++;
	if (map_line[i] == '\0')
		return (true);
	return (map_line[i] != '1');
}

t_map_status	is_open_map_line(const char *map_line)
{
	if (is_line_end_open(map_line) == true
		|| is_line_start_open(map_line) == true)
		return (INVALID_MAP);
	return (VALID_MAP);
}
