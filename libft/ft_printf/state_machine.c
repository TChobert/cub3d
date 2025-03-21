/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machine_states.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:48:48 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/24 15:11:56 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_format_char(const char c)
{
	return (c == FORMAT_CHAR);
}

size_t	run_standard(t_machine *machine, const char current_char)
{
	if (current_char == '\0')
	{
		machine->state = END;
		if (transfer_stash_to_output(machine) == FAILURE)
		{
			machine->state = ERROR;
		}
	}
	else if (is_format_char(current_char))
	{
		machine->state = FLAG;
	}
	else if (push_current_char(machine, current_char) == FAILURE)
	{
		machine->state = ERROR;
	}
	return (1);
}

size_t	run_flag(t_machine *machine, const char current_char)
{
	const t_flag_type	flag_type = get_flag_type_from_char(current_char);

	if (flag_type == NO_FLAG)
	{
		machine->state = CONVERTER;
		return (0);
	}
	machine->active_flags = add_flag(machine->active_flags, flag_type);
	apply_flags_overrides(machine);
	return (1);
}

size_t	run_converter(t_machine *machine, const char current_char)
{
	t_string			str_from_spec;
	t_converter_type	converter_type;

	converter_type = get_converter_type_from_char(current_char);
	str_from_spec.value = apply_converter(converter_type, machine->arguments,
			current_char, machine->active_flags);
	if (converter_type == C_SPEC)
		str_from_spec.len = 1;
	else
		str_from_spec.len = ft_strlen(str_from_spec.value);
	machine->state = STANDARD;
	if (str_from_spec.value == NULL
		|| add_string(machine, str_from_spec) == FAILURE)
	{
		machine->state = ERROR;
	}
	free(str_from_spec.value);
	machine->active_flags = NO_FLAG;
	return (1);
}
