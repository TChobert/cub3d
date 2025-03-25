/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:41:40 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/24 14:28:05 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

#ifndef TEST_MODE

int	launch_game_cub(char *map_file_path)
{
	if (parsing(map_file_path) == PARSING_ERROR)
		return (EXIT_FAILURE);
	exec_game_cub(map_file_path);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		print_error_message_args();
		return (EXIT_FAILURE);
	}
	else
	{
		if (launch_game_cub(av[1]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

#endif