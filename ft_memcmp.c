/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/10 10:39:19 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/10 12:55:58 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	memcmp_8(const uint8_t *s1, const uint8_t *s2)
{
	if (s1[0] - s2[0])
		return ((int)s1[0] - s2[0]);
	if (s1[1] - s2[1])
		return ((int)s1[1] - s2[1]);
	if (s1[2] - s2[2])
		return ((int)s1[2] - s2[2]);
	if (s1[3] - s2[3])
		return ((int)s1[3] - s2[3]);
	if (s1[4] - s2[4])
		return ((int)s1[4] - s2[4]);
	if (s1[5] - s2[5])
		return ((int)s1[5] - s2[5]);
	if (s1[6] - s2[6])
		return ((int)s1[6] - s2[6]);
	return ((int)s1[7] - s2[7]);
}

static int	memcmp_big(const int64_t *s1, const int64_t *s2, size_t n)
{
	while (n > 63)
	{
		if (s1[0] != s2[0])
			return (memcmp_8((uint8_t *)(s1 + 0), (uint8_t *)(s2 + 0)));
		if (s1[1] != s2[1])
			return (memcmp_8((uint8_t *)(s1 + 1), (uint8_t *)(s2 + 1)));
		if (s1[2] != s2[2])
			return (memcmp_8((uint8_t *)(s1 + 2), (uint8_t *)(s2 + 2)));
		if (s1[3] != s2[3])
			return (memcmp_8((uint8_t *)(s1 + 3), (uint8_t *)(s2 + 3)));
		if (s1[4] != s2[4])
			return (memcmp_8((uint8_t *)(s1 + 4), (uint8_t *)(s2 + 4)));
		if (s1[5] != s2[5])
			return (memcmp_8((uint8_t *)(s1 + 5), (uint8_t *)(s2 + 5)));
		if (s1[6] != s2[6])
			return (memcmp_8((uint8_t *)(s1 + 6), (uint8_t *)(s2 + 6)));
		if (s1[7] != s2[7])
			return (memcmp_8((uint8_t *)(s1 + 7), (uint8_t *)(s2 + 7)));
		s1 += 8;
		s2 += 8;
		n -= 64;
	}
	return (0);
}

static int	memcmp_medium(const int64_t *s1, const int64_t *s2, size_t n)
{
	while (n > 7)
	{
		if (*s1 != *s2)
			return (memcmp_8((uint8_t *)s1, (uint8_t *)s2));
		s1++;
		s2++;
		n -= 8;
	}
	return (0);
}

static int	memcmp_small(const uint8_t *s1, const uint8_t *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return ((int)*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		value;

	if (n > 63)
	{
		if ((value = memcmp_big(s1, s2, n)) != 0)
			return (value);
		s1 += (n & (~63ull));
		s2 += (n & (~63ull));
		n &= 63ull;
	}
	if (n > 7)
	{
		if ((value = memcmp_medium(s1, s2, n)) != 0)
			return (value);
		s1 += (n & (~7ull));
		s2 += (n & (~7ull));
		n &= 7ull;
	}
	return (memcmp_small(s1, s2, n));
}
