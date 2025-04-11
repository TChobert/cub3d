/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:08 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/11 15:22:12 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GAME_H
# define CUB_GAME_H

# include "cub_parsing.h"

// STRUCTURES //////////////////////////////////////////////////////////////////

typedef struct s_map_data
{
	char	**map;
	size_t	map_width;
	size_t	map_length;
}				t_map_data;

typedef struct s_game_data
{
	t_map_data			map;
	t_character_data	character_data;
	t_textures			textures;
	t_colors			floor_and_ceiling;
}				t_game_data;

#endif