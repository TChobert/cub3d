/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:33:49 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/23 14:42:13 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_asprintf(char **output, const char *format, ...)
{
	va_list		args;
	int			ret;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	ret = ft_vasprintf(output, format, &args);
	va_end(args);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	int			ret;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	ret = ft_vdprintf(fd, format, &args);
	va_end(args);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			ret;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	ret = ft_vprintf(STDOUT_FILENO, format, &args);
	va_end(args);
	return (ret);
}

/*
int	main(void)
{
	ft_printf("Hello %c%c%c%c%c%c", 'l', 't', 'y', 'y', 'y', 'y');
	return 0;
}
*/
