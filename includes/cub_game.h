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

# include "cub_parsing.h"
# include "mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

// ENUM ////////////////////////////////////////////////////////////////////////

// STRUCTURES //////////////////////////////////////////////////////////////////

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

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

// INIT GAME DATA //
t_parsing_status	parse_game_input(t_game_data *game_data,
						char *map_file_path);
void				transfer_game_data(t_game_data *game_data,
						t_parse_data *parse_data);
void				exec_game_cub(t_game_data *game_data);
int					transfer_map(t_game_data *game_data,
						t_parse_data *parse_data);
void				transfer_textures(t_game_data *game_data,
						t_parse_data *parse_data);
void				transfer_colors(t_game_data *game_data,
						t_parse_data *parse_data);
void				transfer_character_data(t_game_data *game_data,
						t_parse_data *parse_data);

// FREE //
void				game_exit_routine(t_game_data *game_data);

#endif
