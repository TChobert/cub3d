/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_converters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:42:39 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/23 14:33:25 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_c_spec(va_list *args, __attribute__((unused)) const t_flag flags)
{
	const char	c = (unsigned char)va_arg(*args, int);

	return (build_string_from_char(c));
}

char	*get_s_spec(va_list *args, __attribute__((unused)) const t_flag flags)
{
	const char	*str = va_arg(*args, const char *);

	if (str == NULL)
		str = NULL_STRING;
	return (ft_strdup(str));
}

char	*get_no_spec(const char current_char,
		__attribute__((unused)) const t_flag flags)
{
	return (build_string_from_char(current_char));
}
