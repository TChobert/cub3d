/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_no_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:27:44 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/03 18:27:55 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static void	display_map_absence(void)
{
	ft_dprintf(STDERR_FILENO, "Error\nNo map found.\n");
}

void	check_if_no_map(t_parse_data *parse_data, size_t map_size)
{
	if (map_size == 0)
	{
		display_map_absence();
		parser_exit_routine(parse_data);
		exit(FAILURE);
	}
}
