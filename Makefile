##### VARIABLES #####

NAME := cub3d

##### LIBFT #####

PATH_LIBFT := libft/

LIBFT := $(PATH_LIBFT)libft.a

##### SOURCES #####

PATH_SRCS += srcs/
PATH_SRCS += srcs/error/
PATH_SRCS += srcs/parsing/
PATH_SRCS += srcs/parsing/map_file_opener
PATH_SRCS += srcs/parsing/textures_parser
PATH_SRCS += srcs/game/

SRCS += main.c

# error #

SRCS += error_message.c

# srcs parsing #

SRCS += is_valid_map_path.c
SRCS += is_valid_map_file.c
SRCS += map_file_opener.c
SRCS += get_north_texture.c
SRCS += get_south_texture.c
SRCS += get_west_texture.c
SRCS += get_east_texture.c
SRCS += is_xpm_file.c
SRCS += parsing.c

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
TESTS_SRCS_DIR += ./tests/parsing_tests/textures_parser_tests

TESTS_SRCS += main_tests.c

# parsing #

TESTS_SRCS += is_valid_map_path_unit_test.c
TESTS_SRCS += is_valid_map_file_unit_test.c
TESTS_SRCS += is_valid_east_texture_tests.c
TESTS_SRCS += is_valid_south_texture_tests.c
TESTS_SRCS += is_valid_north_texture_tests.c
TESTS_SRCS += is_valid_west_texture_tests.c
TESTS_SRCS += is_valid_north_prefix_tests.c
TESTS_SRCS += is_valid_south_prefix_tests.c
TESTS_SRCS += is_valid_west_prefix_tests.c
TESTS_SRCS += is_valid_east_prefix_tests.c
TESTS_SRCS += is_xpm_file_tests.c

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
