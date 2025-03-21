/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:57:59 by tchobert          #+#    #+#             */
/*   Updated: 2024/08/05 14:41:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static enum e_line_status	extract_line_from_stash(char **line,
													char **stash,
													const char *const endl_ptr)
{
	char *const			temp_stash = *stash;
	enum e_line_status	line_status;

	line_status = COMPLETE_LINE;
	*stash = NULL;
	if (endl_ptr == NULL)
	{
		if (*temp_stash != '\0')
		{
			*line = ft_strndup(temp_stash, ft_strlen(temp_stash));
			if (line == NULL)
				line_status = FAIL;
		}
	}
	else
	{
		*line = ft_strndup(temp_stash, endl_ptr - temp_stash + 1);
		if (*line != NULL)
			*stash = ft_strndup(endl_ptr + 1, ft_strlen(endl_ptr + 1));
		if (*line == NULL || *stash == NULL)
			line_status = FAIL;
	}
	free(temp_stash);
	return (line_status);
}

static enum e_line_status	read_line_from_file(char **line,
												char **stash,
												const int fd)
{
	char				read_buffer[BUFF_SIZE + 1];
	char				*endl_ptr;		
	char *const			temp_stash = *stash;
	const ssize_t		bytes_read = read(fd, read_buffer, BUFF_SIZE);

	if (bytes_read == -1)
		return (FAIL);
	read_buffer[bytes_read] = '\0';
	*stash = ft_strnjoin(*stash, read_buffer, bytes_read);
	free(temp_stash);
	if (*stash == NULL)
		return (FAIL);
	endl_ptr = ft_strchr(*stash, '\n');
	if (endl_ptr != NULL || bytes_read == 0)
	{
		return (extract_line_from_stash(line, stash, endl_ptr));
	}
	return (read_line_from_file(line, stash, fd));
}

static enum e_line_status	get_line_from_stash(char **line, char **stash)
{
	char	*endl_ptr;		

	if (*stash == NULL)
	{
		return (UNCOMPLETE_LINE);
	}
	endl_ptr = ft_strchr(*stash, '\n');
	if (endl_ptr != NULL)
	{
		return (extract_line_from_stash(line, stash, endl_ptr));
	}
	return (UNCOMPLETE_LINE);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD] = {NULL};
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFF_SIZE < 0)
		return (NULL);
	line = NULL;
	if (get_line_from_stash(&line, &stash[fd]) == UNCOMPLETE_LINE)
	{
		if (read_line_from_file(&line, &stash[fd], fd) == FAIL)
		{
			free(line);
			free(stash[fd]);
			line = NULL;
			stash[fd] = NULL;
		}
	}
	return (line);
}

/*
int	main(__attribute__((unused)) int ac, char **av)
{
	int fd;
	char *line = NULL;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (EXIT_SUCCESS);
}
*/
