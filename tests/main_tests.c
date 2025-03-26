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

void	test_parsing_textures(void)
{
	RUN_TEST(is_valid_texture_prefix_tests);
//	RUN_TEST(is_valid_xpm_path_tests);
//	RUN_TEST(is_valid_north_prefix_tests);
	RUN_TEST(is_valid_north_texture_tests);
//	RUN_TEST(is_valid_south_prefix_tests);
	RUN_TEST(is_valid_south_texture_tests);
//	RUN_TEST(is_valid_east_prefix_tests);
	RUN_TEST(is_valid_east_texture_tests);
//	RUN_TEST(is_valid_west_prefix_tests);
	RUN_TEST(is_valid_west_texture_tests);
}

int	main(void)
{
	UNITY_BEGIN();
	setUp();
	printf("PARSING - CHECK PATH MAP FILE\n");
	test_parsing_map_file();
	printf("\n");
	printf("PARSING - CHECK TEXTURES\n");
	test_parsing_textures();
	tearDown();
	return (UNITY_END());
}
