/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_file_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:17:51 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:10:42 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

static bool	is_a_directory(int fd)
{
	char	read_buffer[1];
	ssize_t	bytes_read;

	bytes_read = read(fd, read_buffer, 1);
	if (bytes_read == -1)
	{
		close(fd);
		return (true);
	}
	close(fd);
	return (false);
}

bool	is_valid_map_file(const char *map_file_path)
{
	int		fd;

	fd = open(map_file_path, O_RDONLY);
	if (fd < 0 || is_a_directory(fd) == true)
	{
		return (false);
	}
	return (true);
}
