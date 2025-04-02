/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:31:07 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/01 13:17:20 by racoutte         ###   ########.fr       */
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
void	get_texture_tests(void);
void	get_texture_type_tests(void);
void	is_valid_xpm_path_tests(void);

void	is_valid_texture_prefix_tests(void);

void	get_color_tests(void);

#endif
