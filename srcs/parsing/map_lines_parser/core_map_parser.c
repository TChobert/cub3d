/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_map_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:24:30 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/09 17:40:43 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

t_map_status	core_map_parser(t_map_data *map)
{
	if (check_if_open_map(map) == INVALID_MAP)
	{
		return (INVALID_MAP); //exit? free? msg erreur perso?
	}
	if (check_if_invalid_core_map(map) == INVALID_MAP)
	{
		printf("Salut\n");
		return (INVALID_MAP); //exit? free? msg erreur perso?
	}
	return (VALID_MAP);
}
