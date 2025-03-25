/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_north_texture_tests.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:27:44 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/25 18:10:54 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	get_north_texture_tests(void)
{
	TEST_ASSERT_EQUAL(VALID_TEXTURE, get_north_texture("NO hello.xpm"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, get_north_texture("NP "));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, get_north_texture("NOhello"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, get_north_texture("NO .xpm"));
	TEST_ASSERT_EQUAL(INVALID_TEXTURE, get_north_texture(""));
}
