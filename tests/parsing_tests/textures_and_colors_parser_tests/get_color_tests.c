/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:47:22 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/02 19:47:31 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	get_color_tests(void)
{
	t_parse_data	parse_data;
	static t_color_element	color_elements[] = {
	{.id = "F ", .type = FLOOR},
	{.id = "C ", .type = CEILING},
	};

	ft_bzero(&parse_data, sizeof(parse_data));

	// Testing if floor color field is corectly filled
	TEST_ASSERT_EQUAL(VALID_COLOR, get_color(&parse_data, "F 205, 205, 205", &color_elements[0]));
	TEST_ASSERT_EQUAL(205, (parse_data.colors.floor.r));
	TEST_ASSERT_EQUAL(205, (parse_data.colors.floor.g));
	TEST_ASSERT_EQUAL(205, (parse_data.colors.floor.b));

	// Testing if ceiling color field is corectly filled
	TEST_ASSERT_EQUAL(VALID_COLOR, get_color(&parse_data, "C 210, 210, 210", &color_elements[1]));
	TEST_ASSERT_EQUAL(210, (parse_data.colors.ceiling.r));
	TEST_ASSERT_EQUAL(210, (parse_data.colors.ceiling.g));
	TEST_ASSERT_EQUAL(210, (parse_data.colors.ceiling.b));

	// Testing if floor color field is not impacted by the previous operation
	TEST_ASSERT_EQUAL(205, (parse_data.colors.floor.r));
	TEST_ASSERT_EQUAL(205, (parse_data.colors.floor.g));
	TEST_ASSERT_EQUAL(205, (parse_data.colors.floor.b));

	//ft_bzero(&parse_data, sizeof(parse_data));
}
