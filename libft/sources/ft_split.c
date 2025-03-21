/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:03:01 by tchobert          #+#    #+#             */
/*   Updated: 2024/10/02 15:09:45 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
	{
		++len;
	}
	return (len);
}

static void	skip_separator(char const **s, char c)
{
	size_t	i;

	i = 0;
	while ((*s)[i] == c && (*s)[i] != '\0')
	{
		++(*s);
	}
}

char	**ft_split(char const *s, char c)
{
	const size_t	output_size = ft_count_words(s, c);
	size_t			i;
	size_t			word_len;
	char			**output;

	i = 0;
	output = (char **)malloc(sizeof(char *) * (output_size + 1));
	if (output != NULL)
	{
		output[output_size] = (NULL);
		while (i < output_size)
		{
			skip_separator(&s, c);
			word_len = get_word_len(s, c);
			output[i] = ft_substr(s, 0, word_len);
			if (output[i] == NULL)
			{
				ft_free_and_null(output);
				return (NULL);
			}
			s += word_len;
			++i;
		}
	}
	return (output);
}

// int main(void)
// {
// 	int i = 0;
// 	char **output;

// 	output = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// 	while (output[i] != NULL)
// 	{
// 		printf("%s\n", output[i]);
// 		++i;
// 	}

// 	return (EXIT_SUCCESS);
// }

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	size_t	i;
// 	char	**splitted;

// 	i = 0;
// 	splitted = ft_split(av[1], av[2][0]);
// 	while (splitted[i] != NULL)
// 	{
// 		printf("%s\n", splitted[i]);
// 		++i;
// 	}
// 	return (EXIT_SUCCESS);
// }
