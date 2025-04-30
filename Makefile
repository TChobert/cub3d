##### VARIABLES ##########################################################

NAME := cub3D
NAME_BONUS = cub3D_bonus

##### LIBFT ##############################################################

PATH_LIBFT := libft/

LIBFT := $(PATH_LIBFT)libft.a

##### MLX ################################################################

MLX_DIR = ./minilibx
MLX = $(MLX_DIR)/libmlx_Linux.a
PATH_INCLUDES_MLX = $(MLX_DIR)
MLX_HEADER = $(PATH_INCLUDES_MLX)/mlx.h

##### MLX_LINKS ##########################################################

MLX_LINKS += -L/usr/lib
MLX_LINKS += -lXext
MLX_LINKS += -lX11
MLX_LINKS += -lm
MLX_LINKS += -lz
#MLX_LINKS += -lbsd

##### SOURCES FILES #######################################################
##### MANDATORY ###########################################################

PATH_SRCS += srcs/
PATH_SRCS += srcs/error/
PATH_SRCS += srcs/parsing/
PATH_SRCS += srcs/parsing/map_file_content_getter
PATH_SRCS += srcs/parsing/map_file_opener
PATH_SRCS += srcs/parsing/map_file_parser
PATH_SRCS += srcs/parsing/textures_and_colors_parser
PATH_SRCS += srcs/parsing/map_lines_parser
PATH_SRCS += srcs/parsing/transfer_game_data
PATH_SRCS += srcs/parsing/utils
PATH_SRCS += srcs/game/
PATH_SRCS += srcs/game/init_game
PATH_SRCS += srcs/game/handle_player_inputs
PATH_SRCS += srcs/game/game_events
PATH_SRCS += srcs/game/character_actions
PATH_SRCS += srcs/game/game_loop
PATH_SRCS += srcs/game/render

SRCS += main.c

# error
SRCS += error_message.c

# srcs parsing
SRCS += parsing.c

# map_file_content_getter
SRCS += get_file_content.c
SRCS += save_file_content.c

# map_file_opener
SRCS += is_valid_map_file.c
SRCS += is_valid_map_path.c
SRCS += map_file_opener.c

# map_file_parser
SRCS += parse_map_file.c

# textures_and_colors_parser
SRCS += get_texture_type.c
SRCS += get_texture.c
SRCS += is_valid_texture_prefix.c
SRCS += is_xpm_file.c
SRCS += run_state.c
SRCS += textures_and_colors.c
SRCS += save_error_type.c
SRCS += double_texture.c
SRCS += check_textures.c
SRCS += check_colors.c
SRCS += textures_errors_messages.c

SRCS += get_color.c
SRCS += get_color_type.c
SRCS += is_valid_color_string.c
SRCS += replace_color_strings_without_spaces.c
SRCS += get_color_values.c

# map
SRCS += get_map.c
SRCS += build_map_array.c
SRCS += check_if_no_map.c
SRCS += check_if_invalid_content_below_map.c
SRCS += get_map_part.c
SRCS += get_map_last_line_index.c
SRCS += valid_map_characters.c
SRCS += valid_walls_characters.c
SRCS += core_map_parser.c
SRCS += check_if_open_map.c
SRCS += check_if_invalid_core_map.c
SRCS += check_if_valid_map.c
SRCS += is_valid_number_of_players.c
SRCS += save_character_coordinates.c

# transfer game data
SRCS += transfer_game_data.c
SRCS += transfer_map.c
SRCS += transfer_textures.c
SRCS += transfer_colors.c
SRCS += transfer_character_data.c

# utils
SRCS += is_empty_line.c
SRCS += parser_exit_routine.c
SRCS += copy_map.c

# game
SRCS += run_game.c

# init game
SRCS += init_game.c
SRCS += init_mlx_data.c
SRCS += init_character_data.c

# character actions
SRCS += character_moves.c
SRCS += character_rotations.c
SRCS += is_valid_move.c

# player_input
SRCS += on_key_press.c
SRCS += on_key_release.c

# game events
SRCS += move_character.c
SRCS += on_close_window.c
SRCS += update_game_state.c

# game loop
SRCS += game_loop.c

# render
SRCS += calculate_line_height.c
SRCS += draw_vertical_line.c
SRCS += init_ray.c
SRCS += launch_dda.c
SRCS += raycast.c
SRCS += render.c
SRCS += set_dda_data.c
SRCS += draw_frame_to_window.c
SRCS += draw_color.c
SRCS += draw_wall.c
SRCS += choose_texture.c

# exit_routine

SRCS += game_exit_routine.c

vpath %.c $(PATH_SRCS)

##### SOURCES FILES #######################################################
##### BONUS ###############################################################

PATH_SRCS_BONUS += srcs_bonus/
PATH_SRCS_BONUS += srcs_bonus/error/
PATH_SRCS_BONUS += srcs_bonus/parsing/
PATH_SRCS_BONUS += srcs_bonus/parsing/map_file_content_getter
PATH_SRCS_BONUS += srcs_bonus/parsing/map_file_opener
PATH_SRCS_BONUS += srcs_bonus/parsing/map_file_parser
PATH_SRCS_BONUS += srcs_bonus/parsing/textures_and_colors_parser
PATH_SRCS_BONUS += srcs_bonus/parsing/map_lines_parser
PATH_SRCS_BONUS += srcs_bonus/parsing/transfer_game_data
PATH_SRCS_BONUS += srcs_bonus/parsing/utils
PATH_SRCS_BONUS += srcs_bonus/game/
PATH_SRCS_BONUS += srcs_bonus/game/init_game
PATH_SRCS_BONUS += srcs_bonus/game/handle_player_inputs
PATH_SRCS_BONUS += srcs_bonus/game/game_events
PATH_SRCS_BONUS += srcs_bonus/game/character_actions
PATH_SRCS_BONUS += srcs_bonus/game/game_loop
PATH_SRCS_BONUS += srcs_bonus/game/render

SRCS_BONUS += main_bonus.c

# error
SRCS_BONUS += error_message_bonus.c

# srcs parsing
SRCS_BONUS += parsing_bonus.c

# map_file_content_getter
SRCS_BONUS += get_file_content_bonus.c
SRCS_BONUS += save_file_content_bonus.c

# map_file_opener
SRCS_BONUS += is_valid_map_file_bonus.c
SRCS_BONUS += is_valid_map_path_bonus.c
SRCS_BONUS += map_file_opener_bonus.c

# map_file_parser
SRCS_BONUS += parse_map_file_bonus.c

# textures_and_colors_parser
SRCS_BONUS += get_texture_type_bonus.c
SRCS_BONUS += get_texture_bonus.c
SRCS_BONUS += is_valid_texture_prefix_bonus.c
SRCS_BONUS += is_xpm_file_bonus.c
SRCS_BONUS += run_state_bonus.c
SRCS_BONUS += textures_and_colors_bonus.c
SRCS_BONUS += save_error_type_bonus.c
SRCS_BONUS += double_texture_bonus.c
SRCS_BONUS += check_textures_bonus.c
SRCS_BONUS += check_colors_bonus.c
SRCS_BONUS += textures_errors_messages_bonus.c

SRCS_BONUS += get_color_bonus.c
SRCS_BONUS += get_color_type_bonus.c
SRCS_BONUS += is_valid_color_string_bonus.c
SRCS_BONUS += replace_color_strings_without_spaces_bonus.c
SRCS_BONUS += get_color_values_bonus.c

# map
SRCS_BONUS += get_map_bonus.c
SRCS_BONUS += build_map_array_bonus.c
SRCS_BONUS += check_if_no_map_bonus.c
SRCS_BONUS += check_if_invalid_content_below_map_bonus.c
SRCS_BONUS += get_map_part_bonus.c
SRCS_BONUS += get_map_last_line_index_bonus.c
SRCS_BONUS += valid_map_characters_bonus.c
SRCS_BONUS += valid_walls_characters_bonus.c
SRCS_BONUS += core_map_parser_bonus.c
SRCS_BONUS += check_if_open_map_bonus.c
SRCS_BONUS += check_if_invalid_core_map_bonus.c
SRCS_BONUS += check_if_valid_map_bonus.c
SRCS_BONUS += is_valid_number_of_players_bonus.c
SRCS_BONUS += save_character_coordinates_bonus.c

# transfer game data
SRCS_BONUS += transfer_game_data_bonus.c
SRCS_BONUS += transfer_map_bonus.c
SRCS_BONUS += transfer_textures_bonus.c
SRCS_BONUS += transfer_colors_bonus.c
SRCS_BONUS += transfer_character_data_bonus.c

# utils
SRCS_BONUS += is_empty_line_bonus.c
SRCS_BONUS += parser_exit_routine_bonus.c
SRCS_BONUS += copy_map_bonus.c

# game
SRCS_BONUS += run_game_bonus.c

# init game
SRCS_BONUS += init_game_bonus.c
SRCS_BONUS += init_mlx_data_bonus.c
SRCS_BONUS += init_character_data_bonus.c

# character actions
SRCS_BONUS += character_moves_bonus.c
SRCS_BONUS += character_rotations_bonus.c
SRCS_BONUS += is_valid_move_bonus.c

# player_input
SRCS_BONUS += on_key_press_bonus.c
SRCS_BONUS += on_key_release_bonus.c

# game events
SRCS_BONUS += move_character_bonus.c
SRCS_BONUS += on_close_window_bonus.c
SRCS_BONUS += update_game_state_bonus.c

# game loop
SRCS_BONUS += game_loop_bonus.c

# render
SRCS_BONUS += calculate_line_height_bonus.c
SRCS_BONUS += draw_vertical_line_bonus.c
SRCS_BONUS += init_ray_bonus.c
SRCS_BONUS += launch_dda_bonus.c
SRCS_BONUS += raycast_bonus.c
SRCS_BONUS += render_bonus.c
SRCS_BONUS += set_dda_data_bonus.c
SRCS_BONUS += draw_frame_to_window_bonus.c
SRCS_BONUS += draw_color_bonus.c
SRCS_BONUS += draw_wall_bonus.c
SRCS_BONUS += choose_texture_bonus.c

# exit_routine

SRCS_BONUS += game_exit_routine_bonus.c

vpath %.c $(PATH_SRCS_BONUS)

##### OBJETS ####################################################################

PATH_OBJS := objs/
PATH_OBJS_BONUS := objs_bonus/

OBJS := $(SRCS:%.c=$(PATH_OBJS)%.o)
OBJS_BONUS := $(SRCS_BONUS:%.c=$(PATH_OBJS_BONUS)%.o)

##### HEADERS #####

PATH_INCLUDES := includes/
PATH_INCLUDES_BONUS := includes_bonus/
PATH_INCLUDES_LIBFT := $(PATH_LIBFT)includes/
PATH_INCLUDES_TESTS := includes/
PATH_INCLUDES_UNITY := ./Unity/src

HEADERS += $(PATH_INCLUDES)cub_parsing.h
HEADERS_BONUS += $(PATH_INCLUDES_BONUS)cub_parsing_bonus.h

##### TESTS #####

TESTS_NAME := unit_tests

TESTS_SRCS_DIR += ./tests
TESTS_SRCS_DIR += ./tests/parsing_tests/map_file_opener_tests
TESTS_SRCS_DIR += ./tests/parsing_tests/textures_and_colors_parser_tests

TESTS_SRCS += main_tests.c

# parsing file #

TESTS_SRCS += is_valid_map_path_unit_test.c
TESTS_SRCS += is_valid_map_file_unit_test.c

# parsing textures #

TESTS_SRCS += get_texture_tests.c
TESTS_SRCS += is_xpm_file_tests.c
TESTS_SRCS += get_texture_type_tests.c
TESTS_SRCS += is_valid_texture_prefix_tests.c

# parsing colors #

TESTS_SRCS += get_color_tests.c
TESTS_SRCS += get_color_values_tests.c

## Unity ##

UNITY_SRCS := Unity/src/unity.c

vpath %.c $(TESTS_SRCS_DIR)

##### TESTS OBJETS ##########################################################################

PATH_TESTS_OBJS := objs/tests/

TESTS_OBJS := $(patsubst %.c, $(PATH_TESTS_OBJS)%.o, $(TESTS_SRCS))

##### COMPILATION ###########################################################################

CC := cc
CL := clang

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

ifeq ($(d), 1)
	CFLAGS += -fsanitize=address,undefined -g3
endif

ifeq ($(d), 2)
	CFLAGS += -g3
endif

ifeq ($(d), 3)
	CC = clang
	CFLAGS = -Weverything
endif

##### COLORS #####

GREEN := \033[0;32m
BLUE := \033[0;34m
WHITE := \033[0;37m

##### LINT #####

CLANG_ANALYZE_OPTIONS = --analyze \
						-Werror \
						-Weverything \
						-Wno-unknown-warning-option \
						-Werror \
						-ferror-limit=0 \
						-Xanalyzer -analyzer-output=text \
						-Xanalyzer -analyzer-config \
						-Xanalyzer aggressive-binary-operation-simplification=true \
						-Xanalyzer -analyzer-config \
						-Xanalyzer unroll-loops=true \
						-I includes/ \
						-I libft/includes

CPPCHECK_OPTIONS =  --enable=all \
					--inconclusive \
					--error-exitcode=1 \
					--suppress=missingIncludeSystem \
					--suppress=variableScope \
					-I includes/ \
					-I libft/includes \
					-I$(PATH_INCLUDES_MLX) \
					#--suppress=variableScope \


##### RULES #########################################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(BLUE)Compiling $(NAME)...$(WHITE)"
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LINKS) -o $(NAME) $(LIBFT) $(MLX) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT) -I$(PATH_INCLUDES_MLX)
	@echo "$(GREEN)$(NAME) Compiled!$(WHITE)"

$(MLX):
	@$(MAKE) -C $(MLX_DIR) >/dev/null
	@echo "$(GREEN)Minilibx compiled !$(RESET)"

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADERS)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT) -I$(PATH_INCLUDES_MLX)

$(TESTS_OBJS): $(PATH_TESTS_OBJS)%.o: %.c $(HEADERS)
	@mkdir -p $(PATH_TESTS_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES_TESTS) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT) -I $(PATH_INCLUDES_UNITY)

$(LIBFT):
	@echo "$(BLUE)Compiling $(LIBFT) ...$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT)
	@echo "$(GREEN)$(LIBFT) Compiled ! $(WHITE)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(MLX)
	@echo "$(BLUE)Compiling $(NAME_BONUS)...$(WHITE)"
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX_LINKS) -o $(NAME_BONUS) $(LIBFT) $(MLX) -I $(PATH_INCLUDES_BONUS) -I $(PATH_INCLUDES_LIBFT) -I$(PATH_INCLUDES_MLX)
	@echo "$(GREEN)$(NAME_BONUS) Compiled!$(WHITE)"

$(OBJS_BONUS): $(PATH_OBJS_BONUS)%.o: %.c $(HEADERS_BONUS)
	@mkdir -p $(PATH_OBJS_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES_BONUS) -I $(PATH_INCLUDES_LIBFT) -I$(PATH_INCLUDES_MLX)

clang_analyzer:
	$(CL) $(CFLAGS) $(CLANG_ANALYZE_OPTIONS) -I$(PATH_INCLUDES_MLX) $(wildcard srcs/**/*.c)

cppcheck:
	cppcheck $(CPPCHECK_OPTIONS) $(PATH_SRCS)

norminette: $(SRCS) $(HEADERS)
	norminette $^

tests: $(LIBFT) $(TESTS_OBJS) $(filter-out $(PATH_OBJS)main.o, $(OBJS)) $(UNITY_SRCS)
	@echo "$(BLUE)Tests...$(WHITE)"
	bash setup_unit_tests.sh
	$(CC) $(CFLAGS) -I $(PATH_INCLUDES_TESTS) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_UNITY) -I $(PATH_INCLUDES_LIBFT) $^ -o $(TESTS_NAME) -L$(PATH_LIBFT) -lft -DTEST_MODE

clean:
	@echo "$(BLUE)Cleaning object files...$(WHITE)"
	@rm -rf $(PATH_OBJS) $(PATH_OBJS_BONUS)
	@echo "$(GREEN)Objects cleaned!$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT) fclean

fclean: clean
	@echo "$(BLUE)Removing $(NAME)...$(WHITE)"
	@rm -f $(NAME) $(NAME_BONUS)
	@$(RM) $(TESTS_NAME)
	bash clear_tests.sh
	@echo "$(GREEN)$(NAME) removed!$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re clang_analyzer cppcheck norminette tests
