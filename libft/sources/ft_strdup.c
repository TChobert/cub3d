/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:52:13 by tchobert          #+#    #+#             */
/*   Updated: 2024/07/02 12:15:37 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicated_str;

	duplicated_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (duplicated_str != NULL)
	{
		duplicated_str = ft_strcpy(duplicated_str, s);
	}
	return (duplicated_str);
}

/*
int	main(int ac, char **av)
{
	(void)ac;
	char	*ptr;
	ptr = ft_strdup(av[1]);
	if (ptr == NULL)
	{
		return (-1);
	}
	printf("%s\n", ptr);
	return (EXIT_SUCCESS);
}
*/
