/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_west_texture_tests.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:10:17 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/26 12:10:52 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void get_texture_tests(void)
{
	static t_texture_element texture_elements[] = {
		{.id = "NO", .type = NORTH},
		{.id = "SO", .type = SOUTH},
		{.id = "EA", .type = EAST},
		{.id = "WE", .type = WEST},
	};
	t_game_data game_data;

	ft_bzero(&game_data, sizeof(t_game_data));
	TEST_ASSERT_EQUAL(VALID_TEXTURE, get_texture(&game_data, "NO nord.xpm",
												 &texture_elements[0]));
	TEST_ASSERT_EQUAL(0, ft_strcmp("NO nord.xpm", game_data.textures.north_texture));
	TEST_ASSERT_EQUAL(VALID_TEXTURE, get_texture(&game_data, "EA east.xpm",
		&texture_elements[2]));
	TEST_ASSERT_EQUAL(0, ft_strcmp("EA east.xpm", game_data.textures.east_texture));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, get_texture(&game_data, "NNN nord_false.xpm",
		&texture_elements[0]));
	TEST_ASSERT_EQUAL(0, ft_strcmp("NO nord.xpm", game_data.textures.north_texture));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, get_texture(&game_data, "WE west_false",
		&texture_elements[3]));
	TEST_ASSERT_EQUAL(NULL, game_data.textures.west_texture);
}
