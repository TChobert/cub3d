##### VARIABLES #####

NAME := cub3D

##### LIBFT #####

PATH_LIBFT := libft/

LIBFT := $(PATH_LIBFT)libft.a

##### SOURCES #####

PATH_SRCS += srcs/
PATH_SRCS += srcs/error/
PATH_SRCS += srcs/parsing/
PATH_SRCS += srcs/parsing/map_file_content_getter
PATH_SRCS += srcs/parsing/map_file_opener
PATH_SRCS += srcs/parsing/map_file_parser
PATH_SRCS += srcs/parsing/textures_and_colors_parser
PATH_SRCS += srcs/parsing/map_lines_parser
PATH_SRCS += srcs/parsing/utils
PATH_SRCS += srcs/game/

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

# utils
SRCS += is_empty_line.c
SRCS += parser_exit_routine.c

# srcs game #

SRCS += launch_game.c

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
					#--suppress=variableScope \


##### RULES #####

all: $(NAME)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)...$(WHITE)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT)
	@echo "$(GREEN)$(NAME) Compiled!$(WHITE)"

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADERS)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT)

$(TESTS_OBJS): $(PATH_TESTS_OBJS)%.o: %.c $(HEADERS)
	@mkdir -p $(PATH_TESTS_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES_TESTS) -I $(PATH_INCLUDES) -I $(PATH_INCLUDES_LIBFT) -I $(PATH_INCLUDES_UNITY)

$(LIBFT):
	@echo "$(BLUE)Compiling $(LIBFT) ...$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT)
	@echo "$(GREEN)$(LIBFT) Compiled ! $(WHITE)"

clang_analyzer:
	$(CL) $(CFLAGS) $(CLANG_ANALYZE_OPTIONS) $(wildcard srcs/**/*.c)

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
