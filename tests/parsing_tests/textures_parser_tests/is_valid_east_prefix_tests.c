/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_east_prefix_tests.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:06:50 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/26 12:07:29 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	is_valid_east_prefix_tests(void)
{
	TEST_ASSERT_EQUAL(true, is_valid_east_prefix("EA hello.xpm"));
	TEST_ASSERT_EQUAL(false, is_valid_east_prefix("ES "));
	TEST_ASSERT_EQUAL(false, is_valid_east_prefix("EAhello"));
}
