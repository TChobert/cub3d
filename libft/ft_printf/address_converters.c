/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_converters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:42:22 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/23 14:32:13 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_p_spec(va_list *args, __attribute__((unused)) const t_flag flags)
{
	const uintptr_t	address = (uintptr_t)va_arg(*args, void *);

	if (address == 0)
	{
		return (ft_strdup(NULL_PTR_STRING));
	}
	return (build_unsigned_number_from_base((unsigned long)address,
			HEXADECIMAL_BASE,
			HEXADECIMAL_PREFIX));
}
