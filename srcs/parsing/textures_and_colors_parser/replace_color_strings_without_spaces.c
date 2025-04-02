/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_color_strings_without_spaces.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:16:58 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/02 14:50:31 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static t_color	copy_color_without_spaces(t_color src, t_color dest)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ft_bzero(dest, sizeof(dest));
	while (src[j])
	{
		if (!ft_isspace(src[j]))
		{
			dest[i] = src[j];
			++i;
		}
		++j;
	}
	return (dest);
}

char	*remove_spaces(char *color_string)
{
	t_color	spaceless_color_str;

	spaceless_color_str = malloc(sizeof(char) * (ft_strlen(color_string) + 1));
	if (spaceless_color_str != NULL)
	{
		copy_color_without_spaces(color_string, spaceless_color_str);
	}
	return (spaceless_color_str);
}
