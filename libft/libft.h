/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:29:28 by apuchill          #+#    #+#             */
/*   Updated: 2023/04/10 12:07:47 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCT DECLARATIONS
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_lib_list;


/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
char			*get_next_line_str(int fd);
int				count_words(const char *str, char c);
int				get_next_line(int fd, char **line);
char			*join_str(char const *s1, char const *s2);
int				has_return(char *str);
int				ft_printf(const char *s, ...);
int				ft_atoi(const char *str);
long double		ft_atold(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_intlen(int n);
int				*ft_intsort(int *table, int size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_iscntrl(int c);
int				ft_isdigit(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isstrnull(char *str);
int				ft_isupper(int c);
int				ft_isxdigit(int c);
char			*ft_itoa(int n);
void			ft_lstadd(t_lib_list **alst, t_lib_list *new);
void			ft_lstadd_back(t_lib_list **lst, t_lib_list *new);
void			ft_lstadd_front(t_lib_list **lst, t_lib_list *new);
void			ft_lstclear(t_lib_list **lst, void (*del)(void*));
void			ft_lstdelone(t_lib_list *lst, void (*del)(void *));
void			ft_lstiter(t_lib_list *lst, void (*f)(void *));
t_lib_list		*ft_lstlast(t_lib_list *lst);
t_lib_list		*ft_lstmap(t_lib_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_lib_list		*ft_lstnew(void *content);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
long double		ft_pow(long double n, long double pow);
int				ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char *s);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
int				ft_putstr(char *s);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
void			ft_split_free(char **s);
long double		ft_sqrt(long double x);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
size_t			ft_strlen_2(char **s);
size_t			ft_strlenmodded(const char *s, int nb);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strndup(const char *s1, size_t n);
int				ft_strnrcmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_swap(int *a, int *b);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
