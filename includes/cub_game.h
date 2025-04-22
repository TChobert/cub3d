/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:08 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/11 19:24:49 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GAME_H
# define CUB_GAME_H

# include <X11/X.h>
# include "cub_parsing.h"
# include "mlx.h"

// DEFINES /////////////////////////////////////////////////////////////////////

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

// for MLX

# define MASK_NONE 0
# define EVENT_CLOSE 17

// ENUM ////////////////////////////////////////////////////////////////////////

// STRUCTURES //////////////////////////////////////////////////////////////////

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef enum e_key_codes
{
	W_KEY = 119,
	A_KEY = 97,
	D_KEY = 100,
	S_KEY = 115,
	ESC_KEY = 65307
}			t_key_codes;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
}			t_mlx_data;

typedef struct s_character
{
	t_vector	position;
	t_vector	direction;
	t_vector	plane;
	char		orientation;
}				t_character;

typedef struct s_image_data
{
	char	*img_path;
	void	*img_ptr;
	int		width;
	int		height;
}			t_image_data;

typedef struct s_images_data
{
	t_image_data	north_texture_img;
	t_image_data	south_texture_img;
	t_image_data	east_texture_img;
	t_image_data	west_texture_img;
}				t_images_data;

typedef struct s_map_data
{
	char	**map;
	size_t	map_width;
	size_t	map_length;
}				t_map_data;

typedef struct s_game_data
{
	t_mlx_data		mlx_data;
	t_images_data	images;
	t_map_data		map;
	t_character		character;
	t_colors		floor_and_ceiling;
}				t_game_data;


// FUNCTIONS ///////////////////////////////////////////////////////////////////

void				run_game(t_game_data *game_data);

// INIT GAME DATA //

t_parsing_status	parse_game_input(t_game_data *game_data,
						char *map_file_path);
void				transfer_game_data(t_game_data *game_data,
						t_parse_data *parse_data);
int					transfer_map(t_game_data *game_data,
						t_parse_data *parse_data);
void				transfer_textures(t_game_data *game_data,
						t_parse_data *parse_data);
void				transfer_colors(t_game_data *game_data,
						t_parse_data *parse_data);
void				transfer_character_data(t_game_data *game_data,
						t_parse_data *parse_data);
void				init_game(t_game_data *game_data);

// INIT MLX DATA

int					init_mlx_data(t_mlx_data *mlx_data);

// EVENTS HANDLING

int					on_key_press(int keycode, void *param);
int					on_close_window(void *param);

// FREE //
void				game_exit_routine(t_game_data *game_data);

#endif
