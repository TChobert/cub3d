/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_east_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:01:48 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/26 12:42:29 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

bool	is_valid_east_prefix(const char *texture)
{
	if (ft_strncmp("EA ", texture, 3) != 0)
		return (false);
	return (true);
}

t_texture_status	is_valid_east_texture(const char *texture)
{
	if (is_valid_east_prefix(texture) == false)
		return (INVALID_TEXTURE);
	if (is_valid_xpm_path(texture + 3) == false)
		return (INVALID_TEXTURE);
	return (VALID_TEXTURE);
}

char	*get_east_texture(char *texture)
{
	if (is_valid_east_texture(texture) == INVALID_TEXTURE)
	{
		ft_putstr_fd("Error\nInvalid east texture\n", STDERR_FILENO);
		return (NULL);
	}
	return (texture);
}
