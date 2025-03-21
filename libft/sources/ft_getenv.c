/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:11:58 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/02 15:10:22 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cut_key(char *env_str)
{
	const char	key_value_sep = '=';
	size_t		i;
	char		*output;

	i = 0;
	while (env_str[i] != key_value_sep)
	{
		++i;
	}
	++i;
	output = &env_str[i];
	return (output);
}

char	*ft_getenv(char *key, char **env)
{
	char	*env_string;
	size_t	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], key, ft_strlen(key)) == 0)
		{
			env_string = cut_key(env[i]);
			return (env_string);
		}
		++i;
	}
	return (NULL);
}
