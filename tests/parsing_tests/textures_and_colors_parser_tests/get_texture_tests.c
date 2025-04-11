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
		{.id = "NO ", .type = NORTH},
		{.id = "SO ", .type = SOUTH},
		{.id = "EA ", .type = EAST},
		{.id = "WE ", .type = WEST},
	};
	t_parse_data parse_data;

	ft_bzero(&parse_data, sizeof(t_parse_data));
	TEST_ASSERT_EQUAL(VALID_TEXTURE, get_texture(&parse_data, "NO nord.xpm",
												 &texture_elements[0]));
	TEST_ASSERT_EQUAL(0, ft_strcmp("nord.xpm", parse_data.textures.north_texture));
	TEST_ASSERT_EQUAL(VALID_TEXTURE, get_texture(&parse_data, "EA east.xpm",
		&texture_elements[2]));
	TEST_ASSERT_EQUAL(0, ft_strcmp("east.xpm", parse_data.textures.east_texture));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, get_texture(&parse_data, "NNN nord_false.xpm",
		&texture_elements[0]));
	TEST_ASSERT_EQUAL(0, ft_strcmp("nord.xpm", parse_data.textures.north_texture));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, get_texture(&parse_data, "WE west_false",
		&texture_elements[3]));
	TEST_ASSERT_EQUAL(NULL, parse_data.textures.west_texture);
}
