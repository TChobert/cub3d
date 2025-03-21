/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:42:51 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/23 14:34:38 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_converter(const t_converter_type converter_type,
		va_list *args, const char current_char, const t_flag flags)
{
	static t_converter_function	converter_type_functions[] = {
		get_c_spec,
		get_s_spec,
		get_p_spec,
		get_d_spec,
		get_i_spec,
		get_u_spec,
		get_x_spec,
		get_xup_spec
	};

	if (converter_type == NO_SPEC)
		return (get_no_spec(current_char, flags));
	return (converter_type_functions[converter_type](args, flags));
}
