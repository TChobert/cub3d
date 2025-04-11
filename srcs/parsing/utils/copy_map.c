/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:03:26 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/11 17:03:39 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing.h"

char	**copy_map(char **src, size_t map_size)
{
	char	**map;
	size_t	i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (map_size + 1));
	if (map == NULL)
	{
		ft_dprintf(STDERR_FILENO,
			"Error.\n Malloc failure during copy_map.\n");
		return (NULL);
	}
	map[map_size] = NULL;
	while (i < map_size)
	{
		map[i] = ft_strdup(src[i]);
		if (map[i] == NULL)
		{
			ft_dprintf(STDERR_FILENO,
				"Error\n Malloc failure during copy_map.\n");
			return (NULL);
		}
		++i;
	}
	return (map);
}