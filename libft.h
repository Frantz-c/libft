/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/09 15:38:51 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/15 09:32:01 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <immintrin.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *s);
void	ft_bzero(void *b, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strncat(char *dst, const char *src, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strncpy(char *dst, const char *src, size_t len);
size_t	ft_strnlen(const char *s, size_t maxlen);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *big, const char *little);

#endif
