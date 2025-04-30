/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:04:54 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/30 11:13:22 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

bool	is_empty_line(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isspace(line[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
