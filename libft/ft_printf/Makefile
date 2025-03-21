##### VARIABLES #####

## TARGET ##

NAME := libftprintf.a

## LIBFT ##

LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a
LIB_INCLUDES_DIR := $(LIBFT_DIR)
LIB_HEADER := $(LIB_INCLUDES_DIR)/libft.h

## COMPILATION ##

CC := cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
ifeq ($d, 1)
	CFLAGS += -fsanitize=address,undefined -g3
endif

AR := ar

ARFLAGS := rcs

## SOURCES ##

SRCS += ft_printf.c
SRCS += virtuals_printf.c
SRCS += build_formated_string.c
SRCS += string_utils.c
SRCS += state_machine_utils.c
SRCS += state_machine.c
SRCS += converter_manager.c
SRCS += converter_utils.c
SRCS += numeric_converters.c
SRCS += char_converters.c
SRCS += address_converters.c
SRCS += flag_manager.c

## BONUS ##

BONUS += ft_printf_bonus.c
BONUS += virtuals_printf_bonus.c
BONUS += build_formated_string_bonus.c
BONUS += string_utils_bonus.c
BONUS += state_machine_utils_bonus.c
BONUS += state_machine_bonus.c
BONUS += converter_manager_bonus.c
BONUS += converter_utils_bonus.c
BONUS += numeric_converters_bonus.c
BONUS += char_converters_bonus.c
BONUS += address_converters_bonus.c
BONUS += flag_manager_bonus.c

## BONUS ##

## HEADERS ##

HEADERS := ft_printf.h
INCLUDES_DIR := .

vpath %.h $(INCLUDES_DIR)

## OBJECTS ##

OBJS := $(patsubst %.c, %.o, $(SRCS))

## OBJECTS BONUS ##

OBJS_BONUS := $(patsubst %.c, %.o, $(BONUS))

##### RULES #####

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^ libft/*.o

bonus: $(LIBFT) $(OBJS_BONUS) $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^ libft/*.o

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(LIB_INCLUDES_DIR) -I$(INCLUDES_DIR) -c $< -o $@

$(OBJS_BONUS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(LIB_INCLUDES_DIR) -I$(INCLUDES_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
