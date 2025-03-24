##### VARIABLES #####

NAME := cub3d

##### LIBFT #####

PATH_LIBFT := libft/

LIBFT := $(PATH_LIBFT)libft.a

##### SOURCES #####

PATH_SRCS += srcs/
PATH_SRCS += srcs/error/
PATH_SRCS += srcs/parsing/
PATH_SRCS += srcs/game/

SRCS += main.c

# error #

SRCS += error_message.c

# srcs parsing #

SRCS += check_valid_file.c
SRCS += map_file_opener.c
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

HEADERS += $(PATH_INCLUDES)cub_parsing.h

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

clean:
	@echo "$(BLUE)Cleaning object files...$(WHITE)"
	@rm -rf $(PATH_OBJS)
	@echo "$(GREEN)Objects cleaned!$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT) fclean

fclean: clean
	@echo "$(BLUE)Removing $(NAME)...$(WHITE)"
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) removed!$(WHITE)"
	@$(MAKE) -sC $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re clang_analyzer cppcheck norminette
