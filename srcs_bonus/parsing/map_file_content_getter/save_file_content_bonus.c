/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file_content_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:35:39 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:10:57 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

static size_t	add_line_to_splitted_content(char *file_content,
			char **splitted_file_content)
{
	static size_t	lines_count = 0;
	size_t			line_size;

	line_size = 0;
	while (file_content[line_size] != '\n'
		&& file_content[line_size] != '\0')
	{
		++line_size;
	}
	splitted_file_content[lines_count] = ft_strndup(file_content, line_size);
	if (splitted_file_content[lines_count] == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\n"
			"Malloc failure during split_file_content.\n");
		exit(FAILURE);
	}
	lines_count += 1;
	return (line_size + 1);
}

static void	split_file_content(t_parse_data *parse_data, char *file_content)
{
	char	**splitted_file_content;
	size_t	lines;

	lines = 1;
	splitted_file_content = malloc(sizeof(char *)
			* (parse_data->map_file_lines_number + 1));
	if (splitted_file_content == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\n"
			"Malloc failure during split_file_content.\n");
		parser_exit_routine(parse_data);
		exit(FAILURE);
	}
	splitted_file_content[parse_data->map_file_lines_number] = NULL;
	while (lines < parse_data->map_file_lines_number)
	{
		file_content += add_line_to_splitted_content(file_content,
				splitted_file_content);
		++lines;
	}
	if (*file_content != '\0')
		add_line_to_splitted_content(file_content, splitted_file_content);
	parse_data->map_file_content = splitted_file_content;
}

void	save_file_content(t_parse_data *parse_data, char *file_content)
{
	split_file_content(parse_data, file_content);
	if (parse_data->map_file_content == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error.\n"
			"Failed to save file content. Exit.\n");
		exit(FAILURE);
	}
}
