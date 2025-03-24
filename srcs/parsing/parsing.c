/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:00:48 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/24 14:20:08 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

int	parsing(char *map_file_path)
{
	t_file_data	file_data;

	if (map_file_opener(map_file_path, &file_data.file_fd) == INVALID_MAP_FILE)
		return (PARSING_ERROR);
	printf("End of parsing reached\n");
	return (EXIT_SUCCESS);
}
