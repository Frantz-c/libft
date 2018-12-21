/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:46:19 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 13:51:01 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef	unsigned long int	t_longword;
typedef	unsigned char		t_byte;
typedef	int					t_bool;
typedef	unsigned long		t_ulong;
typedef	unsigned int		t_uint;

# define FT_LWSIZ		8
# define FT_TRUE		1
# define FT_FALSE		0
# define FT_INFINITE	!0
# define FT_IN			0
# define FT_OUT			1
# define FT_ERR			2
# define FT_REMOVE		(void *)0
# define FT_BUFSIZ		64

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** pour la fonction ft_sort_array
*/
typedef	struct		s_sortdata
{
	size_t	l1;
	size_t	l2;
	int		(*cmp)(void *a, void *b);
}					t_sortdata;

/*
** Pour ft_getline
*/
typedef struct		s_file
{
	char			pline[FT_BUFSIZ + 1];
	int				fd;
	struct s_file	*next;
}					t_file;

/*
** Pour ft_get_options
*/
typedef struct		s_options
{
	char				*name;
	char				*value;
	struct s_options	*next;
}					t_options;

/*
** Partie 1
*/
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *dst, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *s1, const char *s2, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_atoi(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** Partie 2
*/
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t len);

/*
** Partie bonus
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Fonctions personelles
*/
size_t				ft_strnlen(const char *s, size_t max);
char				*ft_chrep(char *s, int c, int replace);
size_t				ft_chrep_all(char *s, int c, int replace);
char				*ft_chrrep(char *s, int c, int replace);
char				*ft_strrep(const char *s, const char *search,
								const char *replace);
void				ft_putbin(long n, size_t size, t_uint lf);
char				*ft_strndup(const char *s, size_t len);
int					ft_getline(const int fd, char **line);
char				*ft_strnfcat(char *s1, const char *s2, size_t size);
long				ft_pow(int n, t_uint exp);
void				ft_sort_array(void *a1, size_t elemsiz, size_t len,
									int (*cmp)(void *a, void *b));
void				*ft_memdup(void *srcaddr, size_t size);
char				*ft_strctrim(const char *s, char c);
char				*ft_strtolower(const char *s);
char				*ft_strtoupper(const char *s);
t_options			*ft_get_options(int ac, char **av);
void				ft_print_options(t_options *opt);
void				ft_free_options(t_options **opt);
void				*ft_memrcpy(void *dst, const void *src, size_t n);
void				*ft_mempcpy(void *dst, const void *src, size_t n);
void				*ft_memrchr(const void *dst, int c, size_t n);

#endif
