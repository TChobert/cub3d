/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:48:00 by racoutte          #+#    #+#             */
/*   Updated: 2025/03/24 11:11:50 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSING_H
#define CUB_PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

// ENUM ////////////////////////////////////////////////////////////////////////


// STRUCTURES //////////////////////////////////////////////////////////////////


// FUNCTIONS ///////////////////////////////////////////////////////////////////

// ERROR //
void	print_error_message_args(void);

// PARSING //
int		parsing_map(char *av);

// GAME //
void	exec_game_cub(char *av);

#endif
