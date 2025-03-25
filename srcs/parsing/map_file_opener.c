/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file_opener.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:20:52 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/24 15:37:41 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

void	open_map_file(const char *map_file_path, int *map_fd)
{
	*map_fd = open(map_file_path, O_RDONLY);
	if (*map_fd < 0)
	{
		print_opening_errors(map_file_path);
		exit(FAILURE);
	}
}

t_parsing_status	map_file_opener(const char *map_file_path, int *map_fd)
{
	if (is_valid_map_path(map_file_path) == false)
	{
		print_invalid_path();
		return (INVALID_MAP_FILE);
	}
	if (is_valid_map_file(map_file_path) == false)
	{
		print_opening_errors(map_file_path);
		return (INVALID_MAP_FILE);
	}
	open_map_file(map_file_path, map_fd);
	return (VALID_MAP_FILE);
}
