/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_type_tests.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:58:06 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/31 15:58:19 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	get_texture_type_tests(void)
{
	t_texture_element	*element;

	element = get_texture_type("NO test_north.xpm");
	TEST_ASSERT_EQUAL(0, ft_strcmp("NO ", element->id));
	TEST_ASSERT_EQUAL(-9, ft_strcmp("EA ", element->id));
	TEST_ASSERT_EQUAL(NORTH, element->type);
}
