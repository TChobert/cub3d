/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:41:40 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/11 19:36:37 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_game.h"

#ifndef TEST_MODE

int	launch_game_cub(char *map_file_path)
{
	t_game_data	game_data;

	ft_bzero(&game_data, sizeof(game_data));
	if (parse_game_input(&game_data, map_file_path) == PARSE_ERROR)
		return (EXIT_FAILURE);
	exec_game_cub(&game_data);
	game_exit_routine(&game_data);
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
