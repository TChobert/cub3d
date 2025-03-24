/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:41:40 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/24 11:15:14 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

int	launch_game_cub(char *av)
{
	if (parsing_map(av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	exec_game_cub(av);
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
