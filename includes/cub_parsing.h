/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:48:00 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/28 15:25:15 by racoutte         ###   ########.fr       */
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

# define TEXTURES_OK 0

typedef char *	t_texture;
typedef char **	t_file_data;

// ENUM ////////////////////////////////////////////////////////////////////////

typedef enum e_map_file_status
{
	VALID_MAP_FILE,
	INVALID_MAP_FILE
}			t_map_file_status;

typedef enum e_content_status
{
	VALID_CONTENT,
	INVALID_CONTENT
}			t_content_status;

typedef enum e_parsing_status
{
	PARSE_SUCCESS,
	PARSE_ERROR
}			t_parsing_status;

typedef enum e_texture_status
{
	VALID_TEXTURE,
	INVALID_TEXTURE
}			t_texture_status;

typedef enum e_state
{
	EMPTY_LINE,
	FULL_LINE,
	START,
	END
}			t_state;


// STRUCTURES //////////////////////////////////////////////////////////////////

typedef struct	s_parse_state
{
	t_state	state;
}				t_parse_state;

typedef struct s_game_data
{
	int			file_fd;
	t_texture	north_texture;
	t_file_data	map_file_data;
	size_t		map_file_lines_number;
	bool		textures_and_colors;
	size_t		current_line;
}				t_game_data;

typedef void (*state_function)(t_game_data *game_data, t_parse_state *state);

// FUNCTIONS ///////////////////////////////////////////////////////////////////

// ERROR //
void				print_error_message_args(void);
void				print_opening_errors(const char *map_file_path);
void				print_invalid_path(void);

// PARSING //
t_parsing_status	parsing(char *map_file_path);

t_content_status	parse_map_file(t_game_data *game_data);
void				get_file_content(t_game_data *game_data);
void				save_file_content(t_game_data *game_data,
						char *file_content);
bool				is_valid_map_path(const char *map_file_path);
bool				is_valid_map_file(const char *map_file_path);
t_map_file_status	map_file_opener(const char *map_file_path, int *map_fd);
bool				is_valid_xpm_path(const char *file_path);
t_texture_status	is_valid_north_texture(const char *texture);
char				*get_north_texture(char *texture);
t_texture_status	is_valid_south_texture(const char *texture);
char				*get_south_texture(char *texture);
t_texture_status	is_valid_east_texture(const char *texture);
char				*get_east_texture(char *texture);
t_texture_status	is_valid_west_texture(const char *texture);
char				*get_west_texture(char *texture);

bool				is_valid_texture_prefix(const char *texture,
						const char *prefix);

// GAME //
void				exec_game_cub(char *map_file_path);

#endif
