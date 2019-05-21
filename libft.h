/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/09 15:38:51 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 12:01:39 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE	4096

struct	s_list
{
	void			*data;
	size_t			size;
	struct s_list	*next;
};

typedef struct s_list	t_list;

int		ft_atoi(const char *s);
void	ft_bzero(void *b, size_t n);
char	**ft_explode(const char *str, const char *delim);
int		ft_get_next_line(int fd, char **line);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int val);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_memdel(void **ptr);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr(int nb);
void	ft_putnbr_fd(int nb, int fd);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strcspn(const char *str, const char *delim);
void	ft_strdel(char **str);
char	*ft_strdup(const char *s);
int		ft_strequ(const char *s1, const char *s2);
void	ft_striter(char *str, void (*func)(char *));
void	ft_striteri(char *str, void (*func)(unsigned int, char *));
char	*ft_strjoin(const char *left, const char *right);
size_t	ft_strlcat(char *dst, const char *src, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strmap(char const *str, char (*func)(char));
char	*ft_strmapi(char const *str, char (*func)(unsigned int, char));
char	*ft_strncat(char *dst, const char *src, size_t len);
char	*ft_strnew(size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strndup(const char *str, size_t n);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
size_t	ft_strnlen(const char *s, size_t maxlen);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	**ft_strsplit(const char *str, char c);
size_t	ft_strspn(const char *str, const char *delim);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strsub(const char *s, unsigned int start, size_t len);
char	*ft_strtok(char *str, const char *delim);
char	*ft_strtok_r(char *str, const char *delim, char **oldptr);
char	*ft_strtrim(const char *str);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_wordcount(char *s, const char *delim);

t_list	*ft_lstnew(void *data, size_t size);
void	ft_lstdelone(t_list **alst, void (*func)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*func)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *node);
void	ft_lstiter(t_list *lst, void (*func)(t_list *));
t_list	*ft_lstmap(t_list *lst, t_list *(*func)(t_list *));
void	ft_lstpush(t_list **alst, t_list *node);

#endif
