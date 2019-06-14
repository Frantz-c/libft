/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   barray.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 08:50:35 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/12 09:57:26 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BARRAY_H
# define BARRAY_H

# include <stdlib.h>
# include <stddef.h>
# include "../libft.h"

struct		s_barray
{
	char	*data;
	size_t	usize;
	size_t	msize;
	size_t	align;
};

typedef struct s_barray	t_barray;

t_barray	*array_init(size_t size);
t_barray	*array_init_copy(const char *data, size_t size, size_t buffer_size);
t_barray	*array_init_pointer(char *data, size_t size, size_t buffer_size);

int			array_realloc(t_barray *array, size_t new_size);

int			array_push_char(t_barray *array, char c);
int			array_push_short(t_barray *array, short s);
int			array_push_int(t_barray *array, int i);
int			array_push_long(t_barray *array, long l);
int			array_push_float(t_barray *array, float f);
int			array_push_double(t_barray *array, double d);
int			array_push_ldouble(t_barray *array, long double ld);

int			array_pop_char(t_barray *array, char *c);
int			array_pop_short(t_barray *array, short *s);
int			array_pop_int(t_barray *array, int *i);
int			array_pop_long(t_barray *array, long *l);
int			array_pop_float(t_barray *array, float *f);
int			array_pop_double(t_barray *array, double *d);
int			array_pop_ldouble(t_barray *array, long double *ld);

int			array_push_data(t_barray *array, const char *b, size_t size);
int			array_insert(t_barray *array, const char *b, size_t i, size_t size);

void		array_sort(t_barray *array, size_t elemsize,
			int (*cmp)(void *, void *));

void		array_filter(t_barray *array, size_t elemsize,
			int (*filter)(void *));

void		array_destroy(t_barray *array);

#endif
