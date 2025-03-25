/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_north_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:14:13 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/25 17:35:03 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static bool	is_valid_prefix(const char *texture)
{
	if (ft_strncmp("NO ", texture, 3) != 0)
		return (false);
	return (true);
}

t_texture_status	get_north_texture(const char *texture)
{
	if (is_valid_prefix(texture) == false)
		return (INVALID_TEXTURE);
	// if (is_xpm_file(texture) == false)
	// 	return (INVALID_TEXTURE);
	return (VALID_TEXTURE);
}
