/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:29:51 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/10 17:30:46 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_base_alphanumeric(const char *base)
{
	size_t	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (!ft_isalnum(base[i]))
		{
			return (false);
		}
		++i;
	}
	return (true);
}

static bool	check_base(const char *base)
{
	char	*first_parser;
	char	*second_parser;

	if (!is_base_alphanumeric(base))
	{
		return (false);
	}
	first_parser = (char *)base;
	while (*first_parser != '\0')
	{
		second_parser = first_parser + sizeof(char);
		while (*second_parser != '\0')
		{
			if (*second_parser == *first_parser)
			{
				return (false);
			}
			++second_parser;
		}
		++first_parser;
	}
	return (true);
}

static size_t	get_number_len(long nb, size_t base_size)
{
	size_t	size;

	size = 0;
	while (nb != 0)
	{
		nb /= base_size;
		++size;
	}
	return (size);
}

static void	fill_str_with_nbr(const char *base, char *new_str, unsigned long nb,
								const size_t number_len)
{
	const size_t	base_size = ft_strlen(base);
	size_t			i;

	i = number_len - 1;
	new_str[number_len] = '\0';
	if (nb == 0)
	{
		new_str[0] = '0';
	}
	while (nb != 0)
	{
		new_str[i] = base[nb % base_size];
		nb /= base_size;
		--i;
	}
}

char	*ft_ultoa_base(unsigned long n, const char *base)
{
	const size_t	base_size = ft_strlen(base);
	const size_t	number_len = get_number_len(n, base_size);
	char			*new_str;

	new_str = NULL;
	if (!check_base(base) || base_size <= 1)
	{
		return (new_str);
	}
	new_str = (char *)malloc(sizeof(char) * (number_len + 1));
	if (new_str != NULL)
	{
		fill_str_with_nbr(base, new_str, n, number_len);
	}
	return (new_str);
}

/*
int	main(int ac, char **av)
{
	char	*new_str;
	char	*base = "0123456789";
	(void)ac;
	(void)av;
	new_str = ft_ultoa_base(42, base);
	if (new_str != NULL)
	{
		printf("%s\n", new_str);
		printf("%zu\n", ft_strlen(new_str));
	}
	//printf("%x\n", -1200);
	free(new_str);
	return (EXIT_SUCCESS);
}
*/
