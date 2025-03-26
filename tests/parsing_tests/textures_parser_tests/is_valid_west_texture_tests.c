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

void	is_valid_west_texture_tests(void)
{
	TEST_ASSERT_EQUAL(VALID_TEXTURE, is_valid_west_texture("WE hello.xpm"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_west_texture("WP "));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_west_texture("WEhello"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_west_texture("WE .xpm"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_west_texture(""));
}
