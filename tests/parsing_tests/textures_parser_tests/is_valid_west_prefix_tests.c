/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_west_prefix_tests.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:06:39 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/26 12:08:28 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	is_valid_west_prefix_tests(void)
{
	TEST_ASSERT_EQUAL(true, is_valid_west_prefix("WE hello.xpm"));
	TEST_ASSERT_EQUAL(false, is_valid_west_prefix("WP "));
	TEST_ASSERT_EQUAL(false, is_valid_west_prefix("WEhello"));
}
