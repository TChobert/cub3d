/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:35:47 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/03 16:36:01 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

static void	fill_last_part_array(t_game_data *game_data, char **map_array, size_t	map_size)
{
	size_t	i;

	i = 0;
	while (i < map_size)
	{
		map_array[i] = ft_strdup(game_data->map_file_content[game_data->current_line + i]);
		if (map_array[i] == NULL)
		{
			ft_dprintf(STDERR_FILENO, "Error\nMalloc failure during function fill_map_array.\n");
			parser_exit_routine(game_data);
			exit(FAILURE);
		}
		++i;
	}
}

static char	**get_map_file_last_part(t_game_data *game_data)
{
	char	**last_part_array;
	size_t	last_part_size;

	last_part_size = game_data->map_file_lines_number - game_data->current_line;
	check_if_no_map(game_data, last_part_size);
	last_part_array = (char **)malloc(sizeof(char *) * (last_part_size + 1));
	if (last_part_array == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Error\nMalloc failure during function get_map_file_last_part.\n");
		parser_exit_routine(game_data);
		exit(FAILURE);
	}
	last_part_array[game_data->map_file_lines_number - game_data->current_line] = NULL;
	fill_last_part_array(game_data, last_part_array, last_part_size);
	return (last_part_array);
}

// static bool	is_map_last_line(const char *line)
// {
// 	size_t	i;

// 	if (ft_strchr(line, '1') == NULL)
// 		return (false);
// 	i = 0;
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] != '1' && ft_isspace(line[i]) == false)
// 			return (false);
// 		++i;
// 	}
// 	return (true);
// }

static bool	is_map_last_line(const char *line)
{
    size_t	i;
    bool	found_one;

    if (!line)
        return (false);
    
    found_one = false;
    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '1')
            found_one = true;
        else if (!ft_isspace(line[i]))
        {
            printf("❌ Ligne invalide : |%s| (caractère interdit: %c)\n", line, line[i]);
            return (false);
        }
        ++i;
    }

    if (found_one)
        printf("✅ Ligne valide trouvée : |%s|\n", line);
    return (found_one);
}

static size_t	get_map_last_line_index(t_game_data *game_data, char **map_file_last_part)
{
	size_t	i;

	i = (game_data->map_file_lines_number - game_data->current_line);
	while (i > 0)
	{
		if (is_map_last_line(map_file_last_part[i]))
			return (i);
		--i;
	}
	return (0);
}

static char	**copy_map(char **src, size_t map_size)
{
	char	**map;
	size_t	i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (map_size + 1));
	if (map == NULL)
	{
		printf("Merde\n");
		exit(FAILURE);
	}
	map[map_size] = NULL;
	while (i <= map_size)
	{
		map[i] = ft_strdup(src[i]);
		if (map[i] == NULL)
		{
			printf("Merde 2\n");
			exit(FAILURE);
		}
		++i;
	}
	return (map);
}

static char	**get_map_from_file_last_part(t_game_data *game_data, char **map_file_last_part)
{
	char	**map;
	size_t	last_line_index;

	last_line_index = get_map_last_line_index(game_data, map_file_last_part);
	if (last_line_index == 0)
	{
		ft_dprintf(STDERR_FILENO, "Invalid map\n");
		exit(FAILURE);
	}
	map = copy_map(map_file_last_part, last_line_index);
	return (map);
}

t_map_status	get_map(t_game_data *game_data)
{
	char	**map;
	char	**map_file_last_part;

	map_file_last_part = get_map_file_last_part(game_data);
	map = get_map_from_file_last_part(game_data, map_file_last_part);
	game_data->game_map.map_array = map;
	ft_free_and_null(map_file_last_part);
	ft_display_strs_array(game_data->game_map.map_array, STDOUT_FILENO);
	return (VALID_MAP);
}
