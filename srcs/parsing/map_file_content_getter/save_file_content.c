/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:35:39 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/27 19:35:45 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static size_t	add_line_to_splitted_content(char *file_content,
			char **splitted_file_content)
{
	static	size_t	lines_count = 0;
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
		//exit
	}
	lines_count += 1;
	return (line_size + 1);
}

static void	split_file_content(t_game_data *game_data, char *file_content)
{
	char	**splitted_file_content;

	splitted_file_content = malloc(sizeof(char *) * (game_data->map_file_lines_number + 1));
	// if (splitted_file_content == NULL)
	// {
	// 	//exit
	// }
	splitted_file_content[game_data->map_file_lines_number] = NULL;
	size_t	lines = 1;
	while (lines < game_data->map_file_lines_number)
	{
		file_content += add_line_to_splitted_content(file_content, splitted_file_content);
		++lines;
	}
	if (*file_content != '\0')
		add_line_to_splitted_content(file_content, splitted_file_content);
	game_data->map_file_data = splitted_file_content;
}

void	save_file_content(t_game_data *game_data, char *file_content)
{
	split_file_content(game_data, file_content);
	if (game_data->map_file_data == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error.\n"
			"Failed to save file content. Exit.\n");
		exit(FAILURE);
	}
}
