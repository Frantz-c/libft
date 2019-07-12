/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 10:27:34 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 14:40:35 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	merge_blocks(void *b_left, void *b_right, size_t size,
			struct s_sortblock *x)
{
	size_t	left;
	size_t	right;
	void	*b_copy;

	if ((b_copy = ft_memdup(b_left, x->left * size)) == NULL)
		return ;
	left = 0;
	right = 0;
	while (left < x->left)
	{
		if (right >= x->right)
		{
			ft_memcpy(b_left, b_copy + left * size, size * (x->left - left));
			break ;
		}
		if (x->cmp(b_copy + (left * size), b_right + (right * size)) < 0)
			ft_memcpy(b_left, b_copy + (left++ * size), size);
		else
			ft_memcpy(b_left, b_right + (right++ * size), size);
		b_left += size;
	}
	free(b_copy);
}

void		ft_sort(void *b, size_t elemsize, size_t nitems,
			int (*cmp)(const void *, const void *))
{
	struct s_sortblock	x;

	if (nitems <= 1)
		return ;
	x.cmp = cmp;
	x.left = nitems >> 1;
	x.right = nitems - x.left;
	ft_sort(b, elemsize, x.left, cmp);
	ft_sort(b + x.left * elemsize, elemsize, x.right, cmp);
	merge_blocks(b, b + x.left * elemsize, elemsize, &x);
}
