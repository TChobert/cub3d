/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_values_tests.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:05:06 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/03 15:05:23 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	get_color_values_tests(void)
{
	t_game_data		game_data;
	t_color_values	floor_values;
	t_color_values	ceiling_values;

	ft_bzero(&game_data, sizeof(game_data));
	ft_bzero(&floor_values, sizeof(floor_values));
	ft_bzero(&ceiling_values, sizeof(ceiling_values));

	TEST_ASSERT_EQUAL(VALID_COLOR, get_color_values(&game_data, "205,     205,205",
										&floor_values));
	TEST_ASSERT_EQUAL(floor_values.r, 205);
	TEST_ASSERT_EQUAL(floor_values.g, 205);
	TEST_ASSERT_EQUAL(floor_values.b, 205);

	TEST_ASSERT_EQUAL(VALID_COLOR, get_color_values(&game_data, "110,110,                  110",
		&ceiling_values));
	TEST_ASSERT_EQUAL(ceiling_values.r, 110);
	TEST_ASSERT_EQUAL(ceiling_values.g, 110);
	TEST_ASSERT_EQUAL(ceiling_values.b, 110);
}
