/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_south_prefix_tests.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:06:44 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/26 12:08:00 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	is_valid_south_prefix_tests(void)
{
	TEST_ASSERT_EQUAL(true, is_valid_south_prefix("SO hello.xpm"));
	TEST_ASSERT_EQUAL(false, is_valid_south_prefix("SP "));
	TEST_ASSERT_EQUAL(false, is_valid_south_prefix("SOhello"));
}
