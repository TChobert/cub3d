/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_formated_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:57:28 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/23 19:57:52 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	build_formated_string(t_string *output, const char *format, va_list *args)
{
	static t_state_function	state_functions[] = {
		run_standard,
		run_flag,
		run_converter
	};
	t_machine				machine;

	init_machine(&machine, args);
	while (machine.state != END)
	{
		format += state_functions[machine.state](&machine, *format);
		if (machine.state == ERROR)
		{
			return (FAILURE);
		}
	}
	*output = machine.output_str;
	return (SUCCESS);
}
