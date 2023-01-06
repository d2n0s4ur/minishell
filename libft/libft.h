/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:20:54 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/03 20:19:10 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_gnllist
{
	char				*lastbuffer;
	int					fd;
	struct s_gnllist	*next;
}	t_gnllist;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
unsigned int	ft_strlen(const char *s);
char			*ft_strdup(char *src);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_bzero(void *s, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
size_t			ft_strlcpy(char *dest, char *src, size_t size);
int				ft_atoi(const char *str);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(char *s, int c);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *haystack, \
						const char *needle, size_t len);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlcat(char *dest, char *src, size_t size);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char *s1, char *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));
char			*get_next_line(int fd);
void			ft_free_matrix(char ***martix);
char			*ft_strdup_add_one(char *src, char chr);
void			ft_strcpy(char *dest, char *str, int size);
void			ft_strcpy_add_one(char *dest, char *str, int size, char chr);
char			**ft_dup_matrix(char **martix);
char			**ft_extend_matrix(char **in, char *newstr);
int				ft_countchar(char *s, char c);
int				ft_putmatrix_fd(char **martix, int nl, int fd);
int				ft_strchars_i(const char *s, char *set);
int				ft_isspace(char c);
int				ft_strchr_i(const char *s, int c);
int				ft_matrixlen(char **martix);
char			**ft_matrix_replace_in(char ***big, char **small, int number);
int				ft_putstr_fd(char *s, int fd);
int				ft_putendl_fd(char *s, int fd);
char			*gnl_strchr(char *s, int c);
char			*gnl_strdup_until_add(char *src, int until, int add);
char			*gnl_strcat(char *s1, char *s2);
void			gnl_free(char **to_free);
void			gnl_deletenode(t_gnllist **lst, int fd);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_is_all_digit(char *argv);
char			*ft_str3join(char *s1, char *s2, char *s3);

#endif