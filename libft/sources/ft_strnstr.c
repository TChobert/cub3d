/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:09:58 by tchobert          #+#    #+#             */
/*   Updated: 2024/09/18 13:58:38 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			little_len;
	char			*occurence;

	occurence = (char *)big;
	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	if (*big == '\0' || len == 0 || little_len > len)
		return (NULL);
	i = 0;
	while (i <= len - little_len)
	{
		if (big[i] == *little)
		{
			occurence = (char *)big + i;
			if (ft_strcmp(big + i, little) == 0)
			{
				return (occurence);
			}
		}
		++i;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	big[] = "AAAAA";
	const char	little[] = "AAAA";

	printf("%s\n", ft_strnstr(big, little, 0));
	return (EXIT_SUCCESS);
}
*/
