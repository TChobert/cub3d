/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:28:19 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/24 19:02:49 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// INCLUDES //

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>

# include "libft.h"

// DEFINES //

# define DECIMAL_BASE "0123456789"
# define HEXADECIMAL_BASE "0123456789abcdef"
# define CONVERTERS "cspdiuxX"
# define FLAGS "# +"
# define BUFFER_SIZE 16

# define NULL_STRING "(null)"
# define NULL_PTR_STRING "(nil)"

# define FORMAT_CHAR '%'

# define HEXADECIMAL_PREFIX "0x"
# define PLUS_PREFIX "+"
# define SPACE_PREFIX " "

# define FAILURE -1
# define SUCCESS 0

typedef uint8_t	t_flag;

// TYPEDEFS //

typedef enum e_flag_type
{
	NO_FLAG = 0x00,
	HASH_FLAG = 0x01,
	SPACE_FLAG = 0x02,
	PLUS_FLAG = 0x04
}			t_flag_type;

typedef enum e_converter_type
{
	NO_SPEC = -1,
	C_SPEC,
	S_SPEC,
	P_SPEC,
	D_SPEC,
	I_SPEC,
	U_SPEC,
	X_SPEC,
	X_MAJ_SPEC,
	PERCENT_SPEC
}			t_converter_type;

// TYPEDEFS //

typedef enum e_state
{
	ERROR = -1,
	STANDARD,
	FLAG,
	CONVERTER,
	END
}				t_state;

typedef struct s_string
{
	char		*value;
	size_t		len;
}				t_string;

typedef struct s_machine
{
	t_string	output_str;
	size_t		stash_index;
	va_list		*arguments;
	t_state		state;
	char		stash_buffer[BUFFER_SIZE + 1];
	t_flag		active_flags;
}				t_machine;

typedef size_t	(*t_state_function)(t_machine *, const char);
typedef char	*(*t_converter_function)(va_list *args, const t_flag flags);

// PROTOTYPES//

// Printf
int					ft_printf(const char *format,
						...)__attribute__((format(printf, 1, 2)));
int					ft_dprintf(int fd, const char *format, ...);
int					ft_asprintf(char **output, const char *format, ...);
int					ft_vprintf(int fd, const char *format, va_list *args);
int					ft_vdprintf(int fd, const char *format, va_list	*args);
int					ft_vasprintf(char **output, const char *format,
						va_list *args);

// Parsing & Machine

int					build_formated_string(
						t_string *output,
						const char *format,
						va_list *args);

// Converters Manager

char				*apply_converter(const t_converter_type converter_type,
						va_list *args, const char current_char,
						const t_flag flags);

// Converters

char				*get_c_spec(va_list *args, const t_flag flags);
char				*get_s_spec(va_list *args, const t_flag flags);
char				*get_p_spec(va_list *args, const t_flag flags);
char				*get_d_spec(va_list *args, const t_flag flags);
char				*get_i_spec(va_list *args, const t_flag flags);
char				*get_u_spec(va_list *args, const t_flag flags);
char				*get_x_spec(va_list *args, const t_flag flags);
char				*get_xup_spec(va_list *args, const t_flag flags);
char				*get_percent_spec(va_list *args, const t_flag flags);
char				*get_no_spec(const char current_char, const t_flag flags);

// State Machine

size_t				run_standard(t_machine *machine, const char current_char);
size_t				run_converter(t_machine *machine, const char current_char);
size_t				run_flag(t_machine *machine, const char current_char);
void				init_machine(t_machine *machine, va_list *args);
t_converter_type	get_converter_type_from_char(const char c);
t_flag_type			get_flag_type_from_char(const char c);
void				apply_flags_overrides(t_machine *machine);

// String Management
int					push_current_char(t_machine *machine, const char c);
int					transfer_stash_to_output(t_machine *machine);
int					add_string(t_machine *machine, const t_string new_str);
char				*append_null_to_output_str(t_string *str);
void				add_prefix(char **str, const char *prefix);

// Flag Management

t_flag				add_flag(const t_flag flags, const t_flag flag);
t_flag				remove_flag(const t_flag flags, const t_flag flag);
bool				is_flag_set(const t_flag flags, const t_flag flag);

// Converter utils

char				*build_unsigned_number_from_base(const unsigned long value,
						const char *base, const char *prefix);
char				*build_int_from_base(const int value, const char *base,
						const char *prefix);
char				*get_decimal_int(va_list *args, const char *prefix);
char				*get_unsigned_int_from_base(va_list *args,
						const char *base, const char *prefix);
char				*build_string_from_char(const char c);

#endif
