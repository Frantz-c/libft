/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 11:03:24 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 11:03:47 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
