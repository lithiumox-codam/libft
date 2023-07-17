/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:20:37 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/17 21:31:19 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_vector
{
	void	*data;
	size_t	size;
	size_t	type_size;
	size_t	capacity;
}			t_vector;

bool		ft_vec_init(t_vector *vec, size_t size, size_t type_size);
bool		ft_vec_push(t_vector *vec, void *data);
void		ft_vec_free(t_vector *vec, void (*free_data)(void *));
void		*ft_vec_get(t_vector *vec, size_t index);
void		*ft_vec_pop(t_vector *vec);
void		*ft_vec_remove(t_vector *v, size_t i);
bool		ft_vec_insert(t_vector *v, size_t i, void *data);
size_t		ft_vec_find(t_vector *vec, void *data, int (*cmp)(void *, void *));

#endif
