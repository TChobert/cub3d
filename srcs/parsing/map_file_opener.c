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

static bool	is_not_hide_cub_file(const char *map_file_path)
{
	const size_t	len = ft_strlen(map_file_path);

	if (strncmp(map_file_path + len - 5, "/.cub", len) == 0)
		return (false);
	return (true);
}

static bool	is_not_a_double_cub(const char *map_file_path)
{
	const size_t	len = ft_strlen(map_file_path);

	if (strcmp(".cub.cub", map_file_path) == 0)
		return (false);
	if (len > 8)
	{
		if (strncmp(map_file_path + len - 8, ".cub.cub", len - 8) == 0)
			return (false);
	}
	return (true);
}

t_parsing_file_type	check_map_file_type(const char *map_file_path)
{
	size_t	len;

	len = ft_strlen(map_file_path);
	if (len < 5 || ft_strncmp(map_file_path + len - 4, CUB_SUFFIX,
			strlen(map_file_path)) != 0
		|| is_not_hide_cub_file(map_file_path) == false
		|| is_not_a_double_cub(map_file_path) == false)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid file type. Please enter a"
			" '%s' file to start the game.\n", CUB_SUFFIX);
		return (INVALID_FILE_TYPE);
	}
	return (VALID_FILE_TYPE);
}

t_parsing_opening_status	open_map_file(const char *map_file_path,
								int *map_fd)
{
	*map_fd = open(map_file_path, O_RDONLY);
	if (*map_fd < 0)
	{
		print_opening_errors(map_file_path);
		return (OPENING_FAILURE);
	}
	return (OPENING_SUCCESS);
}

t_parsing_status	map_file_opener(const char *map_file_path, int *map_fd)
{
	if (check_map_file_type(map_file_path) == INVALID_FILE_TYPE)
		return (INVALID_FILE);
	if (open_map_file(map_file_path, map_fd) == OPENING_FAILURE)
		return (INVALID_FILE);
	return (VALID_FILE);
}
