##### VARIABLES #####

## TARGET ##

NAME := libft.a

## COMPILATION ##

CC := cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
# CFLAGS += -fsanitize=address,undefined -g3

AR := ar

ARFLAGS := rcs

## SOURCES ##

SRCS_DIR := sources
PRINTF_DIR := ft_printf
GNL_DIR := get_next_line

SRCS += $(SRCS_DIR)/ft_isalpha.c
SRCS += $(SRCS_DIR)/ft_isdigit.c
SRCS += $(SRCS_DIR)/ft_isalnum.c
SRCS += $(SRCS_DIR)/ft_isascii.c
SRCS += $(SRCS_DIR)/ft_isprint.c
SRCS += $(SRCS_DIR)/ft_strlen.c
SRCS += $(SRCS_DIR)/ft_memset.c
SRCS += $(SRCS_DIR)/ft_bzero.c
SRCS += $(SRCS_DIR)/ft_memcpy.c
SRCS += $(SRCS_DIR)/ft_memmove.c
SRCS += $(SRCS_DIR)/ft_memjoin.c
SRCS += $(SRCS_DIR)/ft_strlcpy.c
SRCS += $(SRCS_DIR)/ft_strlcat.c
SRCS += $(SRCS_DIR)/ft_toupper.c
SRCS += $(SRCS_DIR)/ft_tolower.c
SRCS += $(SRCS_DIR)/ft_strchr.c
SRCS += $(SRCS_DIR)/ft_strrchr.c
SRCS += $(SRCS_DIR)/ft_strcmp.c
SRCS += $(SRCS_DIR)/ft_strncmp.c
SRCS += $(SRCS_DIR)/ft_memchr.c
SRCS += $(SRCS_DIR)/ft_memcmp.c
SRCS += $(SRCS_DIR)/ft_strcat.c
SRCS += $(SRCS_DIR)/ft_strnstr.c
SRCS += $(SRCS_DIR)/ft_atoi.c
SRCS += $(SRCS_DIR)/ft_atol.c
SRCS += $(SRCS_DIR)/ft_calloc.c
SRCS += $(SRCS_DIR)/ft_strdup.c
SRCS += $(SRCS_DIR)/ft_strcpy.c
SRCS += $(SRCS_DIR)/ft_substr.c
SRCS += $(SRCS_DIR)/ft_strjoin.c
SRCS += $(SRCS_DIR)/ft_strtrim.c
SRCS += $(SRCS_DIR)/ft_split.c
SRCS += $(SRCS_DIR)/ft_swap_int.c
SRCS += $(SRCS_DIR)/ft_swap_char.c
SRCS += $(SRCS_DIR)/ft_itoa.c
SRCS += $(SRCS_DIR)/ft_ltoa_base.c
SRCS += $(SRCS_DIR)/ft_ultoa_base.c
SRCS += $(SRCS_DIR)/ft_strmapi.c
SRCS += $(SRCS_DIR)/ft_striteri.c
SRCS += $(SRCS_DIR)/ft_striter.c
SRCS += $(SRCS_DIR)/ft_putchar.c
SRCS += $(SRCS_DIR)/ft_putchar_fd.c
SRCS += $(SRCS_DIR)/ft_putstr_fd.c
SRCS += $(SRCS_DIR)/ft_putendl_fd.c
SRCS += $(SRCS_DIR)/ft_putnbr_fd.c
SRCS += $(SRCS_DIR)/ft_putnbr_hexa.c
SRCS += $(SRCS_DIR)/ft_count_words.c
SRCS += $(SRCS_DIR)/ft_lstnew.c
SRCS += $(SRCS_DIR)/ft_lstadd_front.c
SRCS += $(SRCS_DIR)/ft_lstsize.c
SRCS += $(SRCS_DIR)/ft_lstlast.c
SRCS += $(SRCS_DIR)/ft_lstadd_back.c
SRCS += $(SRCS_DIR)/ft_lstdelone.c
SRCS += $(SRCS_DIR)/ft_lstclear.c
SRCS += $(SRCS_DIR)/ft_lstiter.c
SRCS += $(SRCS_DIR)/ft_lstmap.c
SRCS += $(SRCS_DIR)/ft_strndup.c
SRCS += $(SRCS_DIR)/ft_strncpy.c
SRCS += $(SRCS_DIR)/ft_strnjoin.c
SRCS += $(SRCS_DIR)/ft_free_and_null.c
SRCS += $(SRCS_DIR)/ft_swap_long.c
SRCS += $(SRCS_DIR)/ft_atoi_base.c
SRCS += $(SRCS_DIR)/ft_getenv.c
SRCS += $(SRCS_DIR)/ft_display_strs_array.c
SRCS += $(SRCS_DIR)/ft_list_find_first.c
SRCS += $(SRCS_DIR)/ft_list_first_content_match.c
SRCS += $(SRCS_DIR)/ft_list_find_previous_element.c

# PRINTF #

SRCS += $(PRINTF_DIR)/ft_printf.c
SRCS += $(PRINTF_DIR)/address_converters.c
SRCS += $(PRINTF_DIR)/build_formated_string.c
SRCS += $(PRINTF_DIR)/char_converters.c
SRCS += $(PRINTF_DIR)/converter_manager.c
SRCS += $(PRINTF_DIR)/converter_utils.c
SRCS += $(PRINTF_DIR)/flag_manager.c
SRCS += $(PRINTF_DIR)/numeric_converters.c
SRCS += $(PRINTF_DIR)/state_machine.c
SRCS += $(PRINTF_DIR)/state_machine_utils.c
SRCS += $(PRINTF_DIR)/string_utils.c
SRCS += $(PRINTF_DIR)/virtuals_printf.c

# GET NEXT LINE #

SRCS += $(GNL_DIR)/get_next_line.c
SRCS += $(GNL_DIR)/get_next_line_utils.c

## HEADERS ##

HEADERS_DIR := includes

HEADERS += $(HEADERS_DIR)/libft.h

vpath %.h $(HEADERS_DIR)

## OBJECTS ##

OBJS := $(patsubst %.c, %.o, $(SRCS))

## OBJECTS BONUS ##

OBJS_BONUS := $(patsubst %.c, %.o, $(BONUS))

##### RULES #####

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS): %.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS_DIR)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

