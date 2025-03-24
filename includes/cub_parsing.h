/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:48:00 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/24 15:15:07 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSING_H
# define CUB_PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

# define CUB_SUFFIX ".cub"

// ENUM ////////////////////////////////////////////////////////////////////////

typedef enum e_parsing_status
{
	VALID_MAP_FILE,
	INVALID_MAP_FILE,
	PARSING_ERROR
}			t_parsing_status;

// STRUCTURES //////////////////////////////////////////////////////////////////

typedef struct s_file_data
{
	int	file_fd;
}				t_file_data;

// FUNCTIONS ///////////////////////////////////////////////////////////////////

// ERROR //
void				print_error_message_args(void);
void				print_opening_errors(const char *map_file_path);
void				print_invalid_path(void);

// PARSING //
int					parsing(char *map_file_path);
bool				is_valid_map_path(const char *map_file_path);
bool				is_valid_map_file(const char *map_file_path);
t_parsing_status	map_file_opener(const char *map_file_path, int *map_fd);

// GAME //
void				exec_game_cub(char *map_file_path);

#endif
