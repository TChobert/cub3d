/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_path_unit_test.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:29:50 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/25 15:25:32 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	is_valid_map_path_unit_test(void)
{
	TEST_ASSERT_EQUAL(true, is_valid_map_path("test.cub"));
	TEST_ASSERT_EQUAL(false, is_valid_map_path(".cub"));
	TEST_ASSERT_EQUAL(false, is_valid_map_path(".cub.cub"));
	TEST_ASSERT_EQUAL(false, is_valid_map_path("hello.cub.cub"));
	TEST_ASSERT_EQUAL(false, is_valid_map_path("hello.ber"));
	TEST_ASSERT_EQUAL(false, is_valid_map_path(""));
}
