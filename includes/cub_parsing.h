/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:48:00 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/24 14:24:24 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSING_H
# define CUB_PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

// ENUM ////////////////////////////////////////////////////////////////////////

typedef enum e_parsing_status
{
	VALID_FILE,
	INVALID_FILE,
	PARSING_ERROR
}			t_parsing_status;

// STRUCTURES //////////////////////////////////////////////////////////////////

typedef struct	s_file_data
{
	int	file_fd;
}				t_file_data;


// FUNCTIONS ///////////////////////////////////////////////////////////////////

// ERROR //
void				print_error_message_args(void);

// PARSING //
int					parsing(char *map_file_path);
t_parsing_status	map_file_opener(char *map_file_path, int *fd);

// GAME //
void				exec_game_cub(char *av);

#endif
