/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:33:03 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/26 12:31:17 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void	test_parsing_map_file(void)
{
	RUN_TEST(is_valid_map_path_unit_test);
	RUN_TEST(is_valid_map_file_unit_test);
}

void	test_parsing_textures_and_colors(void)
{
	RUN_TEST(is_valid_xpm_path_tests);
	RUN_TEST(is_valid_texture_prefix_tests);
	RUN_TEST(get_texture_type_tests);
	RUN_TEST(get_texture_tests);
	RUN_TEST(get_color_tests);
	RUN_TEST(get_color_values_tests);
}

int	main(void)
{
	UNITY_BEGIN();
	setUp();
	printf("PARSING - CHECK PATH MAP FILE\n");
	test_parsing_map_file();
	printf("\n");
	printf("PARSING - CHECK TEXTURES AND COLORS\n");
	test_parsing_textures_and_colors();
	tearDown();
	return (UNITY_END());
}
