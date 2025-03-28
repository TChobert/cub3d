/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:48:00 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/28 18:39:15 by racoutte         ###   ########.fr       */
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

typedef enum e_line_state
{
	EMPTY_LINE,
	FULL_LINE,
	COMPLETE
}			t_line_state;

typedef enum e_texture_type
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}			t_texture_type;

// STRUCTURES //////////////////////////////////////////////////////////////////

typedef struct	s_parse_state
{
	t_line_state	state;
}				t_parse_state;

typedef struct	s_texture_element
{
	char			*id;
	t_texture_type	type;
}				t_texture_element;

typedef struct	s_textures
{
	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	east_texture;
	t_texture	west_texture;
}				t_textures;

typedef struct s_game_data
{
	int			file_fd;
	t_file_data	map_file_content;
	size_t		map_file_lines_number;
	size_t		current_line;
	t_textures	textures;
}				t_game_data;

typedef void (*state_function)(t_game_data *game_data, t_parse_state *state);

// FUNCTIONS ///////////////////////////////////////////////////////////////////

// ERROR //
void				print_error_message_args(void);
void				print_opening_errors(const char *map_file_path);
void				print_invalid_path(void);

// PARSING //
t_parsing_status	parsing(char *map_file_path);

void				get_textures_and_colors(t_game_data *game_data);

t_content_status	parse_map_file(t_game_data *game_data);
void				get_file_content(t_game_data *game_data);
void				save_file_content(t_game_data *game_data,
						char *file_content);
bool				is_valid_map_path(const char *map_file_path);
bool				is_valid_map_file(const char *map_file_path);
t_map_file_status	map_file_opener(const char *map_file_path, int *map_fd);
bool				is_valid_xpm_path(const char *file_path);
t_texture_status	get_texture(t_game_data *game_data,
						const char *texture, t_texture_type texture_type);
bool				is_valid_texture_prefix(const char *texture,
						const char *prefix);
void				run_state(t_game_data *game_data, t_parse_state *parse_state);
t_texture_element	*get_texture_type(const char *texture);
bool				is_empty_line(const char *line);

// GAME //
void				exec_game_cub(char *map_file_path);

#endif
