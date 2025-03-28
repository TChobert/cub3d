/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:04:54 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/28 18:05:15 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

bool	is_empty_line(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
