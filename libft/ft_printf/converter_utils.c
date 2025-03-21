/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:43:00 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/23 14:37:53 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*build_unsigned_number_from_base(const unsigned long value,
		const char *base, const char *prefix)
{
	char				*string_number;

	string_number = ft_ultoa_base(value, base);
	if (prefix != NULL)
		add_prefix(&string_number, prefix);
	return (string_number);
}

char	*build_int_from_base(const int value, const char *base,
		const char *prefix)
{
	char				*string_number;

	string_number = ft_ltoa_base(value, base);
	if (prefix != NULL)
		add_prefix(&string_number, prefix);
	return (string_number);
}

char	*get_decimal_int(va_list *args, const char *prefix)
{
	const int	value = va_arg(*args, int);

	if (value < 0)
		prefix = NULL;
	return (build_int_from_base(value, DECIMAL_BASE, prefix));
}

char	*get_unsigned_int_from_base(va_list *args, const char *base,
			const char *prefix)
{
	const unsigned int	value = va_arg(*args, unsigned int);

	return (build_unsigned_number_from_base(value, base, prefix));
}

char	*build_string_from_char(const char c)
{
	char		*new_str;

	new_str = (char *)ft_calloc(2, sizeof(char));
	if (new_str != NULL)
	{
		new_str[0] = c;
	}
	return (new_str);
}
