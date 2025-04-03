/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_texture_prefix_tests.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:00:44 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/26 15:00:53 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	is_valid_texture_prefix_tests(void)
{
	TEST_ASSERT_EQUAL(true, is_valid_texture_prefix("EA hello.xpm", EAST_TEXTURE_PREFIX));
	TEST_ASSERT_EQUAL(true, is_valid_texture_prefix("NO hello.xpm", NORTH_TEXTURE_PREFIX));
	TEST_ASSERT_EQUAL(false, is_valid_texture_prefix("ES ", EAST_TEXTURE_PREFIX));
	TEST_ASSERT_EQUAL(false, is_valid_texture_prefix("EAhello", NORTH_TEXTURE_PREFIX));
	TEST_ASSERT_EQUAL(false, is_valid_texture_prefix("", SOUTH_TEXTURE_PREFIX));
	TEST_ASSERT_EQUAL(false, is_valid_texture_prefix(" ", WEST_TEXTURE_PREFIX));
}
