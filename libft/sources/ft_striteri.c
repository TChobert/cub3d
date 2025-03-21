/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:52:36 by tchobert          #+#    #+#             */
/*   Updated: 2024/05/24 11:52:48 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	print_char(unsigned int index, char *c)
{
	printf("index : %u, caractere : %c\n", index, *c);
}

void	to_upper(unsigned int index, char *c)
{
	(void)index;
	if (*c >= 'a' && *c <= 'z')
	{
		*c = *c - 32;
	}
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (i < s_len)
	{
		f(i, &(s[i]));
		++i;
	}
}
/*
int	main(void)
{
	char	str[] = "bonjour duncan tu fumes quoi tonton MABOUL MABOUL";
	ft_striteri(str, to_upper);
	printf("%s\n", str);
	return (EXIT_SUCCESS);
}
*/
