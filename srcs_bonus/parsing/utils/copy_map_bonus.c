/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racoutte <racoutte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:03:26 by tchobert          #+#    #+#             */
/*   Updated: 2025/04/30 11:13:18 by racoutte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parsing_bonus.h"

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
