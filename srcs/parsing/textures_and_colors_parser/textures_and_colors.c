/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:57 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/28 18:33:57 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

void	get_textures_and_colors(t_game_data *game_data)
{
	t_parse_state	parse_state;
	size_t			i;

	i = 0;
	parse_state.state = EMPTY_LINE;
	while (parse_state.state != COMPLETE)
	{
		run_state(game_data, &parse_state);
	}
	//return (fonction de fin de processus); fonction de fin fait son taff et retourne un t_content_status selon ce qu'elle a trouve
}
