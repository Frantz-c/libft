/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhouppin <mhouppin@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/11 11:54:57 by mhouppin     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/11 14:37:08 by mhouppin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>
# include <unistd.h>

# define NOT_POWER_OF_TWO	(8 * sizeof(size_t))

struct		s_vector
{
	void	*data;
	size_t	elemsize;
	size_t	nitems;
	size_t	maxitems;
	int		(*compar)(const void *, const void *);
	void	*tmp_elem;
	size_t	shift;
	size_t	lock;
};

typedef struct s_vector	t_vector;

t_vector	*vector_init(size_t elemsize);
t_vector	*vector_clone(t_vector *other);

void		*vector_at(t_vector *vec, size_t index);
void		*vector_at_mul(t_vector *vec, size_t index);
void		*vector_at_shl(t_vector *vec, size_t index);

int			vector_insert(t_vector *vec, const void *elem, size_t index);
void		vector_delete(t_vector *vec, size_t index);
void		vector_sort(t_vector *vec);
ssize_t		vector_search(t_vector *vec, const void *elem);
size_t		vector_index(t_vector *vec, const void *elem);
void		vector_destroy(t_vector *vec);

#endif
