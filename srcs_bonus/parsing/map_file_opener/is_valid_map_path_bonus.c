/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_path_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:53:05 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:10:46 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

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

static bool	has_only_a_cub_suffix(const char *map_file_path)
{
	size_t	len;

	len = ft_strlen(map_file_path);
	if (len < 5 || ft_strncmp(map_file_path + len - 4, CUB_SUFFIX,
			strlen(map_file_path)) != 0)
	{
		return (false);
	}
	return (true);
}

bool	is_valid_map_path(const char *map_file_path)
{
	if (has_only_a_cub_suffix(map_file_path) == false
		|| is_not_hide_cub_file(map_file_path) == false
		|| is_not_a_double_cub(map_file_path) == false)
	{
		return (false);
	}
	return (true);
}
