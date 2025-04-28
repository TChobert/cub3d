##### VARIABLES #####

NAME := cub3D

##### LIBFT #####

PATH_LIBFT := libft/

LIBFT := $(PATH_LIBFT)libft.a

##### MLX #####

MLX_DIR = ./minilibx
MLX = $(MLX_DIR)/libmlx_Linux.a
PATH_INCLUDES_MLX = $(MLX_DIR)
MLX_HEADER = $(PATH_INCLUDES_MLX)/mlx.h

##### MLX_LINKS #####

MLX_LINKS += -L/usr/lib
MLX_LINKS += -lXext
MLX_LINKS += -lX11
MLX_LINKS += -lm
MLX_LINKS += -lz
#MLX_LINKS += -lbsd

##### SOURCES #####

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

# error #

SRCS += error_message.c

# srcs parsing #

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

#map
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

#transfer game data
SRCS += transfer_game_data.c
SRCS += transfer_map.c
SRCS += transfer_textures.c
SRCS += transfer_colors.c
SRCS += transfer_character_data.c

# utils
SRCS += is_empty_line.c
SRCS += parser_exit_routine.c
SRCS += copy_map.c

### srcs game ###

SRCS += run_game.c

#init game
SRCS += init_game.c
SRCS += init_mlx_data.c
SRCS += init_character_data.c

#character actions
SRCS += character_moves.c
SRCS += character_rotations.c
SRCS += is_valid_move.c

#player_input
SRCS += on_key_press.c
SRCS += on_key_release.c

#game events
SRCS += move_character.c
SRCS += on_close_window.c
SRCS += update_game_state.c

#game loop
SRCS += game_loop.c

#render
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

#exit_routine

SRCS += game_exit_routine.c

vpath %.c $(PATH_SRCS)

##### OBJETS #####

PATH_OBJS := objs/

OBJS := $(SRCS:%.c=$(PATH_OBJS)%.o)

##### HEADERS #####

PATH_INCLUDES := includes/
PATH_INCLUDES_LIBFT := $(PATH_LIBFT)includes/
PATH_INCLUDES_TESTS := includes/
PATH_INCLUDES_UNITY := ./Unity/src

HEADERS += $(PATH_INCLUDES)cub_parsing.h

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

##### TESTS OBJETS #####

PATH_TESTS_OBJS := objs/tests/

TESTS_OBJS := $(patsubst %.c, $(PATH_TESTS_OBJS)%.o, $(TESTS_SRCS))

##### COMPILATION #####

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


##### RULES #####

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
	@rm -rf $(PATH_OBJS)
	@echo "$(GREEN)Objects cleaned!$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT) fclean

fclean: clean
	@echo "$(BLUE)Removing $(NAME)...$(WHITE)"
	@rm -f $(NAME)
	@$(RM) $(TESTS_NAME)
	bash clear_tests.sh
	@echo "$(GREEN)$(NAME) removed!$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re clang_analyzer cppcheck norminette tests
