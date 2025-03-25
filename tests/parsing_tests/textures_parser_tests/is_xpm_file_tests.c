/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_xpm_file_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:50:07 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/25 18:08:31 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	is_valid_xpm_path_tests(void)
{
	TEST_ASSERT_EQUAL(true, is_valid_xpm_path("NO hello.xpm"));
	TEST_ASSERT_EQUAL(false, is_valid_xpm_path("NP hey.ber"));
	TEST_ASSERT_EQUAL(false, is_valid_xpm_path("NOhello"));
	TEST_ASSERT_EQUAL(false, is_valid_xpm_path("NOhelloxpm"));
	TEST_ASSERT_EQUAL(false, is_valid_xpm_path(".xpm"));
}
