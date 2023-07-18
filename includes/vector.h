/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:20:37 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 22:11:43 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_vector
{
	void	*data;
	size_t	lenght;
	size_t	type_size;
	size_t	capacity;
}			t_vector;

void		*ft_vec_init(t_vector *vec, size_t capacity,
				size_t type_size) __attribute__((malloc));
void		*ft_vec_get(t_vector *vec, size_t index);
void		*ft_vec_pop(t_vector *vec);
void		*ft_vec_remove(t_vector *v, size_t i, void (*f)(void *));
void		*ft_vec_find(t_vector *vec, void *data, int (*cmp)(void *, void *));
void		ft_vec_apply(t_vector *vec, void (*f)(void *));
void		ft_vec_free(t_vector *vec, void (*free_data)(void *));
bool		ft_vec_insert(t_vector *v, size_t i, void *data);
bool		ft_vec_push(t_vector *vec, void *data);
bool		ft_vec_resize(t_vector *vec, size_t new_size);

#endif
