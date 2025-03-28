/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:33:03 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/25 15:23:53 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void setUp(void)
{
	// Rien à initialiser pour l'instant
}

void tearDown(void)
{
	// Rien à nettoyer pour l'instant
}

int	main(void)
{
	UNITY_BEGIN();
	setUp();
	RUN_TEST(is_valid_map_path_unit_test);
	RUN_TEST(is_valid_map_file_unit_test);
	tearDown();
	return (UNITY_END());
}
