/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dprintf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:09:53 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 12:10:07 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_dprintf(int fd, const char *fmt, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, fmt);
	ret = ft_vdprintf(fd, fmt, ap);
	va_end(ap);
	return (ret);
}
