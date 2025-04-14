/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:35:29 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/02 19:09:20 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

// static bool	is_same_texture(t_texture current_texture,
// 				t_texture texture_to_compare)
// {
// 	if (current_texture != NULL && texture_to_compare != NULL)
// 	{
// 		if (ft_strcmp(current_texture, texture_to_compare) == 0)
// 			return (true);
// 	}
// 	return (false);
// }

// static void	get_all_textures(t_texture *all_textures,
//					t_parse_data *parse_data)
// {
// 	all_textures[0] = parse_data->textures.north_texture;
// 	all_textures[1] = parse_data->textures.south_texture;
// 	all_textures[2] = parse_data->textures.east_texture;
// 	all_textures[3] = parse_data->textures.west_texture;
// }

// bool	is_double_texture(t_parse_data *parse_data)
// {
// 	t_texture	all_textures[4];
// 	size_t		i;
// 	size_t		j;

// 	get_all_textures(all_textures, parse_data);
// 	i = 0;
// 	while (i < 4)
// 	{
// 		j = i + 1;
// 		while (j < 4)
// 		{
// 			if (is_same_texture(all_textures[i], all_textures[j]) == true)
// 			{
// 				return (true);
// 			}
// 			++j;
// 		}
// 		++i;
// 	}
// 	return (false);
// }
