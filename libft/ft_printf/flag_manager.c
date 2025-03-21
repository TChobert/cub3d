/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:43:10 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/23 14:39:49 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	add_flag(const t_flag flags, const t_flag flag)
{
	return (flags | flag);
}

t_flag	remove_flag(const t_flag flags, const t_flag flag)
{
	return (flags & ~flag);
}

bool	is_flag_set(const t_flag flags, const t_flag flag)
{
	return (flags & flag);
}
