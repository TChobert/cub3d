/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_xpm_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:53:01 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/25 18:05:10 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static bool	is_not_hide_xpm_file(const char *file_path)
{
	const size_t	len = ft_strlen(file_path);

	if (len < 5)
		return (ft_strcmp(file_path, ".xpm") != 0);
	else if (ft_strncmp(file_path + len - 5, "/.xpm", len) == 0)
		return (false);
	return (true);
}

static bool	has_xpm_suffix(const char *file_path)
{
	size_t	len;

	len = ft_strlen(file_path);
	if (len < 5 || ft_strncmp(file_path + len - 4, XPM_SUFFIX,
			strlen(file_path)) != 0)
	{
		return (false);
	}
	return (true);
}

bool	is_valid_xpm_path(t_game_data *game_data, const char *file_path)
{
	char	*trimmed_path;

	trimmed_path = ft_strtrim(file_path, WHITESPACES);
	if (trimmed_path == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Erro\nMalloc fail in is_valid_xpm_path.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	if (is_not_hide_xpm_file(trimmed_path) == false
		|| has_xpm_suffix(trimmed_path) == false)
	{
		free(trimmed_path);
		return (false);
	}
	free(trimmed_path);
	return (true);
}
