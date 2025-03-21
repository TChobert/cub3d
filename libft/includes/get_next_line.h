/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:11:46 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/02 15:07:43 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// INCLUDES //

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# include "libft.h"

// DEFINES //

# ifndef BUFF_SIZE
#  define BUFF_SIZE 10
# endif

# define MAX_FD 1024

enum	e_line_status
{
	FAIL,
	UNCOMPLETE_LINE,
	COMPLETE_LINE
};

// PROTOTYPES //

//size_t			ft_strlen(const char *str);
//char				*ft_strchr(const char *s, int c);
//void				ft_strncpy(char *dest, const char *src, size_t size);
//char				*ft_strndup(const char *src, size_t size);
//char				*ft_strnjoin(char *s1, char *s2, size_t max);

char				*get_next_line(int fd);

#endif
