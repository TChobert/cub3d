/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:43:52 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/23 17:39:40 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	push_current_char(t_machine *machine, const char c)
{
	machine->stash_buffer[machine->stash_index] = c;
	++machine->stash_index;
	if (machine->stash_index == BUFFER_SIZE)
	{
		return (transfer_stash_to_output(machine));
	}
	return (SUCCESS);
}

int	transfer_stash_to_output(t_machine *machine)
{
	char	*temp;

	temp = machine->output_str.value;
	machine->output_str.value = ft_memjoin(machine->output_str.value,
			machine->stash_buffer,
			machine->output_str.len,
			machine->stash_index);
	machine->output_str.len += machine->stash_index;
	free(temp);
	ft_bzero(machine->stash_buffer, sizeof(machine->stash_buffer));
	machine->stash_index = 0;
	if (machine->output_str.value == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int	add_string(t_machine *machine, const t_string new_str)
{
	char	*temp;

	if (transfer_stash_to_output(machine) == FAILURE)
		return (FAILURE);
	temp = machine->output_str.value;
	machine->output_str.value = ft_memjoin(machine->output_str.value,
			new_str.value,
			machine->output_str.len,
			new_str.len);
	machine->output_str.len += new_str.len;
	free(temp);
	if (machine->output_str.value == NULL)
		return (FAILURE);
	return (SUCCESS);
}

char	*append_null_to_output_str(t_string *str)
{
	char	*output_str;

	output_str = (char *)malloc(sizeof(char) * (str->len + 1));
	if (output_str != NULL)
	{
		ft_memmove(output_str, str->value, str->len);
		output_str[str->len] = '\0';
	}
	free(str->value);
	return (output_str);
}

void	add_prefix(char **str, const char *prefix)
{
	char	*prefixed_str;

	prefixed_str = ft_strjoin(prefix, *str);
	free(*str);
	*str = prefixed_str;
}
