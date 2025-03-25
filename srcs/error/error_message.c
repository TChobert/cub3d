/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:50:54 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/24 15:39:16 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

void	print_error_message_args(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("Wrong number of args\n", STDERR_FILENO);
}

void	print_opening_errors(const char *map_file_path)
{
	if (errno == EACCES)
		ft_dprintf(STDERR_FILENO, "Error\n%s: permission denied.\n",
			map_file_path);
	else if (errno == ENOENT)
		ft_dprintf(STDERR_FILENO, "Error\n%s: no such file found.\n",
			map_file_path);
	else if (errno == EISDIR)
		ft_dprintf(STDERR_FILENO, "Error\n%s: is a directory.\n",
			map_file_path);
	else
		ft_dprintf(STDERR_FILENO, "Error\n%s: opening error.\n",
			map_file_path);
}

void	print_invalid_path(void)
{
	ft_dprintf(STDERR_FILENO, "Error\nInvalid file type. Please enter a"
		" '%s' file to start the game.\n", CUB_SUFFIX);
}
