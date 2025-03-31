/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_texture_prefix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:25:26 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/26 13:26:37 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

bool	is_valid_texture_prefix(const char *texture, const char *texture_id)
{
	char	*prefix;

	prefix = ft_strjoin(texture_id, " ");
	if (prefix == NULL)
	{
		ft_dprintf(STDERR_FILENO,
			"Error.\n Malloc failure during textures analyze.\n");
		exit(FAILURE);
	}
	if (ft_strncmp(prefix, texture, 3) != 0)
	{
		free(prefix);
		return (false);
	}
	free(prefix);
	return (true);
}
