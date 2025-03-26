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

static char	*build_data_line(t_game_data *game_data)
{
	char	*data_line;
	char	*line;
	char	*temp_data_line;

	data_line = ft_strdup("");
	if (data_line == NULL)
		return (NULL);
	line = get_next_line(game_data->file_fd);
	while (line != NULL)
	{
		temp_data_line = data_line;
		if (ft_asprintf(&data_line, "%s%s", data_line, line) == -1)
		{
			return (NULL);
		}
		free(line);
		line = get_next_line(game_data->file_fd);
		free(temp_data_line);
	}
	free(line);
	return (data_line);
}

static void	get_file_content(t_game_data *game_data, char *data_line)
{
	game_data->map_file_data = ft_split(data_line, '\n');
	if (game_data->map_file_data == NULL)
	{
		//print
		exit(FAILURE);
	}
}

void	duplicate_file_content(t_game_data *game_data)
{
	char	*data_line;

	data_line = build_data_line(game_data);
	if (data_line == NULL)
	{
		//error a print
		exit(FAILURE);
	}
	get_file_content(game_data, data_line);
	free(data_line);
}
