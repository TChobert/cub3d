/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_error_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:44:40 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/01 13:45:15 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

void	save_error_type(t_error_type error_type, t_game_data *game_data)
{
	game_data->parse_error_info.error_type = error_type;
	game_data->parse_error_info.invalid_element
		= ft_strdup(game_data->map_file_content[game_data->current_line]);
}
