/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_map_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:24:30 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/10 15:10:42 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_map_status	core_map_parser(t_map_data *map)
{
	if (check_if_open_map(map) == INVALID_MAP)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid map.\n");
		return (INVALID_MAP); //exit? free? msg erreur perso?
	}
	if (check_if_invalid_core_map(map) == INVALID_MAP)
	{
		printf("Salut\n");
		ft_dprintf(STDERR_FILENO, "Error\nInvalid map.\n");
		return (INVALID_MAP); //exit? free? msg erreur perso?
	}
	if (is_valid_number_of_players(map->players_number) == false)
	{
		ft_dprintf(STDERR_FILENO, "Error\nInvalid number of players.\n");
		return (INVALID_MAP); //exit? free?
	}
	return (VALID_MAP);
}
