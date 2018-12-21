/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fcordon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 22:16:45 by fcordon      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 11:26:38 by fcordon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		memcmp_byte(t_byte *p1, t_byte *p2)
{
	if (*p1 != *p2 || !*p1)
		return ((*p1 - *p2));
	if (p1[1] != p2[1] || !p1[1])
		return ((p1[1] - p2[1]));
	if (p1[2] != p2[2] || !p1[2])
		return ((p1[2] - p2[2]));
	if (p1[3] != p2[3] || !p1[3])
		return ((p1[3] - p2[3]));
	if (p1[4] != p2[4] || !p1[4])
		return ((p1[4] - p2[4]));
	if (p1[5] != p2[5] || !p1[5])
		return ((p1[5] - p2[5]));
	if (p1[6] != p2[6] || !p1[6])
		return ((p1[6] - p2[6]));
	return ((p1[7] - p2[7]));
}

static int		memcmp_same_alignement(const t_longword *s1,
						const t_longword *s2)
{
	const t_longword	repeat_one = 0x0101010101010101UL;
	const t_longword	black_hole = 0x8080808080808080UL;
	t_longword			word;

	while (FT_INFINITE)
	{
		word = *s1;
		if (word != *s2 || ((word - repeat_one) & ~word & black_hole) != 0)
		{
			return (memcmp_byte((t_byte *)s1, (t_byte *)s2));
		}
		s1++;
		s2++;
	}
	return (0);
}

static int		memcmp_not_same_alignement(const t_longword *s1,
						t_longword s2, size_t shift)
{
	const t_longword	repeat_one = 0x0101010101010101UL;
	const t_longword	black_hole = 0x8080808080808080UL;
	const size_t		shr = shift * 8;
	const size_t		shl = (8 - shift) * 8;
	t_longword			merge;

	s2 -= shift;
	while (FT_INFINITE)
	{
		merge = *(t_longword *)s2 >> shr | *(t_longword *)(s2 + 1) << shl;
		if (*s1 != merge || ((merge - repeat_one) & ~merge & black_hole) != 0)
		{
			return (memcmp_byte((t_byte *)s1, (t_byte *)(s2 + shift)));
		}
		s1 += 8;
		s2 += 8;
	}
	return (0);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	int	result;

	while ((t_longword)s1 % 8)
	{
		if ((result = (*((t_byte *)s1) - *((t_byte *)s2))) || *s1 == '\0')
			return (result);
		s1 += 1;
		s2 += 1;
	}
	if ((t_longword)s2 % 8 == 0)
		return (memcmp_same_alignement((t_longword *)s1, (t_longword *)s2));
	else
	{
		return (memcmp_not_same_alignement(
					(t_longword *)s1, (t_longword)s2, (size_t)s2 % 8));
	}
	while (FT_INFINITE)
	{
		if ((result = (*(t_byte *)s1 - *(t_byte *)s2)) || *s1 == '\0')
			break ;
		s1 += 1;
		s2 += 1;
	}
	return (result);
}
