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

bool	is_valid_texture_prefix(const char *texture, const char *prefix)
{
	if (ft_strncmp(prefix, texture, 3) != 0)
	{
		return (false);
	}
	return (true);
}
