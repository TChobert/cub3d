/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtuals_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:30:43 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/23 19:30:47 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vasprintf(char **output, const char *format, va_list *args)
{
	int			ret;
	t_string	str;

	ret = build_formated_string(&str, format, args);
	*output = append_null_to_output_str(&str);
	if (ret == FAILURE)
		return (FAILURE);
	return (str.len);
}

int	ft_vdprintf(int fd, const char *format, va_list	*args)
{
	int		ret;
	char	*formated_str;

	ret = ft_vasprintf(&formated_str, format, args);
	if (ret == FAILURE)
		return (FAILURE);
	ret = write(fd, formated_str, ret);
	free(formated_str);
	return (ret);
}

int	ft_vprintf(int fd, const char *format, va_list *args)
{
	if (format == NULL)
	{
		return (-1);
	}
	return (ft_vdprintf(fd, format, args));
}
