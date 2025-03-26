/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_west_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:01:57 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/26 12:42:42 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

bool	is_valid_west_prefix(const char *texture)
{
	if (ft_strncmp("WE ", texture, 3) != 0)
		return (false);
	return (true);
}

t_texture_status	is_valid_west_texture(const char *texture)
{
	if (is_valid_west_prefix(texture) == false)
		return (INVALID_TEXTURE);
	if (is_valid_xpm_path(texture + 3) == false)
		return (INVALID_TEXTURE);
	return (VALID_TEXTURE);
}

char	*get_west_texture(char *texture)
{
	if (is_valid_west_texture(texture) == INVALID_TEXTURE)
	{
		ft_putstr_fd("Error\nInvalid west texture\n", STDERR_FILENO);
		return (NULL);
	}
	return (texture);
}
