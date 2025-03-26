/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:48:00 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/26 12:46:06 by racoutte         ###   ########.fr       */
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
# define XPM_SUFFIX ".xpm"
# define SPACE " "

# define NORTH_TEXTURE_PREFIX "NO "
# define SOUTH_TEXTURE_PREFIX "SO "
# define WEST_TEXTURE_PREFIX "WE "
# define EAST_TEXTURE_PREFIX "EA "

typedef char *	t_texture;

// ENUM ////////////////////////////////////////////////////////////////////////

typedef enum e_parsing_status
{
	VALID_MAP_FILE,
	INVALID_MAP_FILE,
	PARSING_ERROR
}			t_parsing_status;

typedef enum e_texture_status
{
	VALID_TEXTURE,
	INVALID_TEXTURE
}			t_texture_status;

// STRUCTURES //////////////////////////////////////////////////////////////////

typedef struct s_game_data
{
	int			file_fd;
	t_texture	north_texture;
}				t_game_data;

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
bool				is_valid_xpm_path(const char *file_path);
t_texture_status	is_valid_north_texture(const char *texture);
//bool				is_valid_north_prefix(const char *texture);
char				*get_north_texture(char *texture);
t_texture_status	is_valid_south_texture(const char *texture);
//bool				is_valid_south_prefix(const char *texture);
char				*get_south_texture(char *texture);
t_texture_status	is_valid_east_texture(const char *texture);
//bool				is_valid_east_prefix(const char *texture);
char				*get_east_texture(char *texture);
t_texture_status	is_valid_west_texture(const char *texture);
//bool				is_valid_west_prefix(const char *texture);
char				*get_west_texture(char *texture);

bool				is_valid_texture_prefix(const char *texture,
						const char *prefix);

// GAME //
void				exec_game_cub(char *map_file_path);

#endif
