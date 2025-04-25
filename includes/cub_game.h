/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:08 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/23 18:26:07 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GAME_H
# define CUB_GAME_H

# include <X11/X.h>
# include <math.h>
# include "cub_parsing.h"
# include "mlx.h"

// DEFINES /////////////////////////////////////////////////////////////////////

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

// ENUM ////////////////////////////////////////////////////////////////////////

// STRUCTURES //////////////////////////////////////////////////////////////////

typedef struct	s_map_coord
{
	int	x;
	int	y;
}				t_map_coord;

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef enum e_key_state
{
	KEY_FREE = 0,
	KEY_PRESSED = 1
}			t_key_state;

typedef enum e_key_codes
{
	W_KEY = 119,
	A_KEY = 97,
	D_KEY = 100,
	S_KEY = 115,
	ESC_KEY = 65307,
	RIGHT_ARROW = 65363,
	LEFT_ARROW = 65361,
}			t_key_codes;

typedef struct	s_ray
{
	t_vector	ray_dir;
	t_map_coord	map;
	t_vector	side_dist;
	t_vector	delta_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct	s_player_input
{
	t_key_state	w;
	t_key_state	a;
	t_key_state	s;
	t_key_state	d;
	t_key_state	left_arrow;
	t_key_state	right_arrow;
}				t_player_input;

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
	char	*pixel_info;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}			t_image_data;

typedef struct s_images_data
{
	t_image_data	north_texture_img;
	t_image_data	south_texture_img;
	t_image_data	east_texture_img;
	t_image_data	west_texture_img;
}				t_images_data;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	t_image_data	frame_img;
}			t_mlx_data;

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
	t_player_input	player_inputs;
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
void				init_character_data(t_game_data *game_data);

// INIT MLX DATA

int					init_mlx_data(t_game_data *game_data);

// CHARACTER ACTIONS
int					move_left(t_game_data *game_data);
int					move_right(t_game_data *game_data);
int					move_backward(t_game_data *game_data);
int					move_forward(t_game_data *game_data);
void				rotate_right(t_game_data *game_data);
void				rotate_left(t_game_data *game_data);

// PLAYER INPUTS HANDLING

int					on_key_press(int keycode, void *param);
int					on_key_released(int keycode, void *param);

// GAME LOOP & RENDER
int					update_game_state(t_game_data *game_data);
int					game_loop(t_game_data *game_data);
void				calculate_line_height(t_game_data *game_data, t_ray *ray);
void				draw_vertical_line(t_image_data *img, int x, t_ray *ray);
void				init_ray(t_game_data *game_data, t_ray *ray, size_t	x);
void				launch_dda(t_game_data *game_data, t_ray *ray);
int					raycast(t_game_data *game_data);
int					render(t_game_data *game_data);
void				set_dda_data(t_game_data *game_data, t_ray *ray);

// EVENTS HANDLING

int					move_character(t_game_data *game_data);
int					on_close_window(void *param);

// FREE //
void				game_exit_routine(t_game_data *game_data);

#endif
