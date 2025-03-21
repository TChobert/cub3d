/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:48:29 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/24 16:16:23 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_machine(t_machine *machine, va_list *args)
{
	ft_bzero(machine, sizeof(t_machine));
	machine->arguments = args;
	machine->state = STANDARD;
	machine->active_flags = NO_FLAG;
}

t_converter_type	get_converter_type_from_char(const char c)
{
	t_converter_type		spec_type;

	spec_type = 0;
	while (CONVERTERS[spec_type] != '\0')
	{
		if (CONVERTERS[spec_type] == c)
			return (spec_type);
		++spec_type;
	}
	return (NO_SPEC);
}

// static t_flag_type	get_flag_type_from_char(const char c)
// {
// 	size_t i = 0

// 	i = 0;
// 	while (FLAGS[i] != '\0')
// 	{
// 		if (FLAGS[i] == c)
// 			return 0x01 << i;
// 		++flag_type;
// 	}
// 	return (NO_FLAG_FOUND);
// }

t_flag_type	get_flag_type_from_char(const char c)
{
	const char	*flag_ptr = ft_strchr(FLAGS, c);

	if (flag_ptr == NULL)
	{
		return (NO_FLAG);
	}
	return (0x01 << (flag_ptr - FLAGS));
}

void	apply_flags_overrides(t_machine *machine)
{
	if (is_flag_set(machine->active_flags, PLUS_FLAG))
	{
		machine->active_flags = remove_flag(machine->active_flags, SPACE_FLAG);
	}
}
