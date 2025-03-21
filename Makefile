##### VARIABLES #####

NAME := cub3d

##### LIBFT #####

##### SOURCES #####

PATH_SRCS += srcs/

SRCS += main.c

vpath %.c $(PATH_SRCS)

##### OBJETS #####

PATH_OBJS := objs/

OBJS := $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

##### HEADERS #####

PATH_INCLUDES := includes/

HEADERS += $(PATH_INCLUDES)test_main.h

##### COMPILATION #####

CC := cc

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
						-Weverything \
						-Wno-unknown-warning-option \
						-Werror \
						-ferror-limit=0 \
						-Xanalyzer -analyzer-output=text \
						-Xanalyzer -analyzer-config \
						-Xanalyzer aggressive-binary-operation-simplification=true \
						-Xanalyzer -analyzer-config \
						-Xanalyzer unroll-loops=true
						-I includes/ \

CPPCHECK_OPTIONS =  --enable=all \
					--inconclusive \
					--error-exitcode=1 \
					--suppress=missingIncludeSystem \
					--suppress=variableScope


##### RULES #####

all: $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)...$(WHITE)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) Compiled!$(WHITE)"

$(OBJS): $(PATH_OBJS)%.o: %.c $(HEADERS)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(PATH_INCLUDES)

clang_analyzer:
	$(CC) $(CFLAGS) $(CLANG_ANALYZE_OPTIONS) $(SRCS)

cppcheck:
	cppcheck $(CPPCHECK_OPTIONS) $(PATH_SRCS)

clean:
	@echo "$(BLUE)Cleaning object files...$(WHITE)"
	@rm -rf $(PATH_OBJS)
	@echo "$(GREEN)Objects cleaned!$(WHITE)"

fclean: clean
	@echo "$(BLUE)Removing $(NAME)...$(WHITE)"
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) removed!$(WHITE)"

re: fclean all

.PHONY: all clean fclean re clang_analyzer cppcheck norminette