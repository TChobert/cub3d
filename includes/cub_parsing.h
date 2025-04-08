/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:48:00 by racoutte          #+#    #+#             */
/*   Updated: 2025/04/07 16:58:43 by racoutte         ###   ########.fr       */
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
# define VALID_PLAYER_CHAR "NSEW"

typedef char *	t_texture;
typedef char *	t_color;
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

typedef enum e_color_status
{
	VALID_COLOR,
	INVALID_COLOR
}			t_color_status;

typedef enum e_map_status
{
	VALID_MAP,
	INVALID_MAP
}			t_map_status;

typedef enum e_line_state
{
	EMPTY_LINE,
	TEXTURE,
	COLOR,
	END_OF_PROCESS
}			t_line_state;

typedef enum e_color_type
{
	FLOOR,
	CEILING
}			t_color_type;

typedef enum e_rgb
{
	RED,
	GREEN,
	BLUE
}			t_rgb;

typedef enum e_texture_type
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}			t_texture_type;

typedef enum e_error_type
{
	NO_ERROR,
	INVALID_ID,
	INVALID_XPM,
	IS_NOT_A_PATH,
	DOUBLE_ELEMENT,
	INVALID_RGB_VALUE,
	INVALID_COLOR_FORMAT
}			t_error_type;

// STRUCTURES //////////////////////////////////////////////////////////////////

typedef struct s_parse_error_info
{
	t_error_type	error_type;
	char			*invalid_element;
}				t_parse_error_info;

typedef struct s_parse_state
{
	t_line_state	state;
}				t_parse_state;

typedef struct s_color_element
{
	char			*id;
	t_color_type	type;
}				t_color_element;

typedef struct s_texture_element
{
	char			*id;
	t_texture_type	type;
}				t_texture_element;

typedef struct s_textures
{
	bool		is_invalid_texture;
	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	east_texture;
	t_texture	west_texture;
}				t_textures;

typedef struct s_color_values
{
	bool	is_full;
	int		r;
	int		g;
	int		b;
}				t_color_values;

typedef struct s_colors
{
	t_color_values	ceiling;
	t_color_values	floor;
}				t_colors;

typedef struct s_map_data
{
	char	**map_array;
	size_t	map_lines_number;
	bool	is_player;
}				t_map_data;

typedef struct s_game_data
{
	int					file_fd;
	t_file_data			map_file_content;
	size_t				map_file_lines_number;
	size_t				current_line;
	t_textures			textures;
	t_colors			colors;
	t_parse_error_info	parse_error_info;
	t_map_data			game_map;
}				t_game_data;

typedef void	(*t_state_func)(t_game_data *game_data, t_parse_state *state);
typedef void	(*t_texture_error_msg)(const char *invalid_element);

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
						const char *texture, t_texture_element *texture_type);
bool				is_valid_texture_prefix(const char *texture,
						const char *texture_id);
void				run_state(t_game_data *game_data,
						t_parse_state *parse_state);
t_texture_element	*get_texture_type(const char *texture);
bool				is_empty_line(const char *line);
void				save_error_type(t_error_type error_type,
						t_game_data *game_data);
bool				is_double_texture(t_game_data *game_data);
void				check_textures(t_game_data *game_data);

t_color_element		*get_color_type(const char *color);
t_color_status		get_color(t_game_data *game_data, const char *color,
						t_color_element *color_type);
void				check_colors(t_game_data *game_data);
t_color_status		is_valid_color_string(const char *color);
t_color_status		get_color_values(t_game_data *game_data,
						const char *color_values, t_color_values *color_field);
char				*remove_spaces(char *color_string);
t_map_status		get_map(t_game_data *game_data);
void				check_if_no_map(t_game_data *game_data, size_t map_size);
void				check_if_invalid_content_below_map(t_game_data *game_data);
char				**get_map_part(t_game_data *game_data);
size_t				get_map_last_line_index(t_game_data *game_data,
						char **map_file_last_part);
bool				is_map_last_line(const char *line);

t_map_status		check_if_valid_first_and_last_wall_line(
						t_map_data *map_data);
t_map_status		check_if_valid_map_characters(t_map_data *map_data);

void				parser_exit_routine(t_game_data *game_data);

// ERRORS DISPLAYING

void				no_error(const char *invalid_element);
void				invalid_id(const char *invalid_element);
void				invalid_xpm(const char *invalid_element);
void				is_not_a_path(const char *invalid_element);
void				double_element(const char *invalid_element);

// GAME //
void				exec_game_cub(char *map_file_path);

#endif
