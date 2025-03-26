/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_east_texture_tests.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:08:55 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/26 12:36:47 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	is_valid_east_texture_tests(void)
{
	TEST_ASSERT_EQUAL(VALID_TEXTURE, is_valid_east_texture("EA hello.xpm"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_east_texture("EP"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_east_texture("EAhello"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_east_texture("EA .xpm"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_east_texture(""));
}
