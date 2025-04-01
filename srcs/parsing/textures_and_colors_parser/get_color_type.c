/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:55:29 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/01 19:55:43 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static bool	is_color_match(const char *color_id, const char *color)
{
	return (ft_strncmp(color_id, color, ft_strlen(color_id)) == 0);
}

t_color_element	*get_color_type(const char *color)
{
	static t_color_element	color_elements[] = {
	{.id = "F ", .type = FLOOR},
	{.id = "C ", .type = CEILING},
	};
	size_t					array_size;
	size_t					i;

	i = 0;
	array_size = sizeof(color_elements) / sizeof(*color_elements);
	while (i < array_size)
	{
		if (is_color_match(color_elements[i].id, color))
			return (&color_elements[i]);
		++i;
	}
	return (NULL);
}
