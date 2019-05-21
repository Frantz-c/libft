/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_clean_format.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 14:46:38 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 14:48:59 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_clean_format(t_format *format)
{
	if (format->flags & PF_MINUS)
		format->flags &= (~PF_ZERO);
	if (format->flags & PF_PLUS)
		format->flags &= (~PF_SPACE);
	if (ft_strchrnul("cdisu", format->specifier))
		format->flags &= (~PF_SHARP);
	if (ft_strchrnul("uoxX", format->specifier))
		format->flags &= ~(PF_SPACE | PF_PLUS);
	if (ft_strchrnul("DOUF", format->specifier))
	{
		format->specifier += 32;
		format->flags |= PF_LONG;
		format->flags &= ~(PF_CHAR | PF_SHORT | PF_LDOUBLE);
	}
	if (format->specifier == 'p')
	{
		format->flags |= PF_LONG | PF_SHARP;
		format->flags &= ~(PF_CHAR | PF_SHORT | PF_LDOUBLE);
	}
	if (format->precision < 0)
		format->precision = 0;
}
