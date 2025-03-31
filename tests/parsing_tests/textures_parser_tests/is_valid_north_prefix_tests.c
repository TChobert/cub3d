/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_north_prefix_tests.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:44:47 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/25 17:49:18 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	is_valid_north_prefix_tests(void)
{
	TEST_ASSERT_EQUAL(true, is_valid_north_prefix("NO hello.xpm"));
	TEST_ASSERT_EQUAL(false, is_valid_north_prefix("NP "));
	TEST_ASSERT_EQUAL(false, is_valid_north_prefix("NOhello"));
}
