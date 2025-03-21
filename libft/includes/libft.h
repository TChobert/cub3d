/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:07:13 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/10 10:50:24 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// INCLUDES --------------------------------------------------------------------

# include "ft_printf.h"
# include "get_next_line.h"

# include <stdint.h>
# include <unistd.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <assert.h>

# include <stdio.h>

// DEFINES ---------------------------------------------------------------------

# define ASCII_ZERO 48

// TYPEDEFS --------------------------------------------------------------------

typedef unsigned char	t_byte;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

// PROTOTYPES ------------------------------------------------------------------

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memjoin(void const *m1, void const *m2,
			const size_t len_m1, const size_t len_m2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_swap_int(int *a, int *b);
void	ft_swap_char(char *a, char *b);
char	*ft_itoa(int n);
char	*ft_ltoa_base(long n, const char *base);
char	*ft_ultoa_base(unsigned long n, const char *base);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_striter(char *s, int (*f)(int));
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_hexa(unsigned long nb);
size_t	ft_count_words(const char *str, char sep);
void	ft_strncpy(char *dest, const char *src, size_t size);
char	*ft_strndup(const char *src, size_t size);
char	*ft_strnjoin(char *s1, char *s2, size_t max);
void	ft_free_and_null(char **strs_array);
void	ft_swap_long(long *a, long *b);
int		ft_atoi_base(const char *nb, unsigned int base);
char	*ft_getenv(char *key, char **env);
void	ft_display_strs_array(char **array, int fd);

// LIST FUNCTIONS :

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_list_find_first(t_list *list, void *element,
			bool (*predicate)(void *, void *));
void	*ft_list_find_first_content_match(t_list *list, void *element,
			bool (*predicate)(void *, void *));
t_list	*ft_list_find_previous_element(t_list *lst, t_list *node);

#endif
