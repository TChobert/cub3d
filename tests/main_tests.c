/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:33:03 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/25 14:33:13 by tchobert         ###   ########.fr       */
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
	is_valid_map_path_unit_test();
	return (UNITY_END());
}