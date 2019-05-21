/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_vprintf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 12:09:14 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 12:09:48 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_vprintf(const char *fmt, va_list ap)
{
	return (ft_vdprintf(1, fmt, ap));
}
