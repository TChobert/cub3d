/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_south_texture_tests.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:09:38 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/26 12:10:13 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	is_valid_south_texture_tests(void)
{
	TEST_ASSERT_EQUAL(VALID_TEXTURE, is_valid_south_texture("SO hello.xpm"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_south_texture("SP "));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_south_texture("SOhello"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_south_texture("SO .xpm"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, is_valid_south_texture(""));
}
