/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_file_unit_test.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:21:19 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/25 15:26:39 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	is_valid_map_file_unit_test(void)
{
	TEST_ASSERT_EQUAL(false, is_valid_map_file("./test.cub"));
	TEST_ASSERT_EQUAL(false, is_valid_map_file("no_right.cub"));
}
