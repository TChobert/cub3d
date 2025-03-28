/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:00:25 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/28 18:21:04 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static bool	is_texture_match(const char *texture_id, const char *texture)
{
	return (ft_strncmp(texture_id, texture, ft_strlen(texture_id)) == 0);
}

t_texture_element	*get_texture_type(const char *texture)
{
	static t_texture_element	texture_elements[] = {
		{.id = "NO", .type = NORTH},
		{.id = "SO", .type = SOUTH},
		{.id = "EA", .type = EAST},
		{.id = "WE", .type = WEST},
	};

	size_t	array_size;
	size_t	i;
	i = 0;
	array_size = sizeof(texture_elements) / sizeof(*texture_elements);
	while (i < array_size)
	{
		if (is_texture_match(texture_elements[i].id, texture))
			return (&texture_elements[i]);
		++i;
	}
	return (NULL);
}
