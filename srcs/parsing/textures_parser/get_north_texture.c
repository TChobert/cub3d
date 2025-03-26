/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_north_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:14:13 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/26 12:42:35 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_texture_status	is_valid_north_texture(const char *texture)
{
	if (is_valid_texture_prefix(texture, NORTH_TEXTURE_PREFIX) == false)
		return (INVALID_TEXTURE);
	if (is_valid_xpm_path(texture + 3) == false)
		return (INVALID_TEXTURE);
	return (VALID_TEXTURE);
}

char	*get_north_texture(char *texture)
{
	if (is_valid_north_texture(texture) == INVALID_TEXTURE)
	{
		ft_putstr_fd("Error\nInvalid north texture\n", STDERR_FILENO);
		return (NULL);
	}
	return (texture);
}
