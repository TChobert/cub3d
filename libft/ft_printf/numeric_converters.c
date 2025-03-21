/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_converters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:43:33 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/23 14:53:26 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_d_spec(va_list *args, const t_flag flags)
{
	char	*prefix;

	prefix = NULL;
	if (is_flag_set(flags, PLUS_FLAG))
		prefix = PLUS_PREFIX;
	else if (is_flag_set(flags, SPACE_FLAG))
		prefix = SPACE_PREFIX;
	return (get_decimal_int(args, prefix));
}

char	*get_i_spec(va_list *args, const t_flag flags)
{
	return (get_d_spec(args, flags));
}

char	*get_u_spec(va_list *args, __attribute__((unused)) const t_flag flags)
{
	return (get_unsigned_int_from_base(args, DECIMAL_BASE, NULL));
}

char	*get_x_spec(va_list *args, const t_flag flags)
{
	char	*prefix;

	prefix = NULL;
	if (is_flag_set(flags, HASH_FLAG))
		prefix = HEXADECIMAL_PREFIX;
	return (get_unsigned_int_from_base(args, HEXADECIMAL_BASE, prefix));
}

char	*get_xup_spec(va_list *args, const t_flag flags)
{
	return (ft_striter(get_x_spec(args, flags), ft_toupper));
}
