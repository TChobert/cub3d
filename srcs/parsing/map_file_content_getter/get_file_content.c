/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_file_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:08:12 by tchobert          #+#    #+#             */
/*   Updated: 2025/03/26 18:08:23 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static void	display_strings_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_printf("%s", array[i]);
		ft_printf("\n");
		++i;
	}
}

static char	*read_entire_file(t_game_data *game_data)
{
	char	*file_content;
	char	*current_line;
	char	*temp;

	file_content = ft_strdup("");
	if (file_content == NULL)
		return (NULL);
	current_line = get_next_line(game_data->file_fd);
	while (current_line != NULL)
	{
		temp = file_content;
		if (ft_asprintf(&file_content, "%s%s", file_content,
			current_line) == -1)
		{
			return (NULL);
		}
		free(current_line);
		current_line = get_next_line(game_data->file_fd);
		free(temp);
		++game_data->map_file_lines_number;
	}
	free(current_line);
	return (file_content);
}

void	get_file_content(t_game_data *game_data)
{
	char	*file_content;

	file_content = read_entire_file(game_data);
	if (file_content == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error.\n"
			"Failed to read file content. Exit.\n");
		exit(FAILURE);
	}
	save_file_content(game_data, file_content);
	close (game_data->file_fd);
	display_strings_array(game_data->map_file_data);
	free(file_content);
}
