/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:08:12 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/28 18:18:37 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static char	*read_entire_file(t_parse_data *parse_data)
{
	char	*file_content;
	char	*current_line;
	char	*temp;

	file_content = ft_strdup("");
	if (file_content == NULL)
		return (NULL);
	current_line = get_next_line(parse_data->file_fd);
	while (current_line != NULL)
	{
		temp = file_content;
		if (ft_asprintf(&file_content, "%s%s", file_content,
				current_line) == -1)
		{
			return (NULL);
		}
		free(current_line);
		current_line = get_next_line(parse_data->file_fd);
		free(temp);
		++parse_data->map_file_lines_number;
	}
	free(current_line);
	return (file_content);
}

void	get_file_content(t_parse_data *parse_data)
{
	char	*file_content;

	file_content = read_entire_file(parse_data);
	if (file_content == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error.\n"
			"Failed to read file content. Exit.\n");
		exit(FAILURE);
	}
	save_file_content(parse_data, file_content);
	close (parse_data->file_fd);
	free(file_content);
}
