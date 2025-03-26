/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:31:07 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/26 12:46:20 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

// INCLUDES //

# include <stdio.h>
# include <stdlib.h>

# include "unity.h"
# include "libft.h"
# include "cub_parsing.h"

// PROTOTYPES //

void	is_valid_map_path_unit_test(void);
void	is_valid_map_file_unit_test(void);
void	is_valid_north_texture_tests(void);
void	is_valid_north_prefix_tests(void);
void	is_valid_south_texture_tests(void);
void	is_valid_south_prefix_tests(void);
void	is_valid_east_texture_tests(void);
void	is_valid_east_prefix_tests(void);
void	is_valid_west_texture_tests(void);
void	is_valid_west_prefix_tests(void);
void	is_valid_xpm_path_tests(void);

void	is_valid_texture_prefix_tests(void);

#endif
