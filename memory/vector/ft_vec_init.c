/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:19:09 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/21 04:06:39 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Initializes a vector
 *
 * @param vec The vector to initialize
 * @param capacity The initial size of the vector
 * @param type_size The size of the content of the vector
 * @return void * The initialized vector or NULL if malloc fails
 */
void	*ft_vec_init(t_vector *vec, size_t capacity, size_t type_size,
		void (*free_data)(void *))
{
	vec->data = malloc(capacity * type_size);
	if (!vec->data)
		return (NULL);
	vec->lenght = 0;
	vec->capacity = capacity;
	vec->type_size = type_size;
	vec->f = free_data;
	vec->loc = vec;
	vec->find = ft_vec_find;
	vec->find_multiple = ft_vec_find_multiple;
	vec->apply = ft_vec_apply;
	vec->pop = ft_vec_pop;
	vec->remove = ft_vec_remove;
	vec->insert = ft_vec_insert;
	vec->push = ft_vec_push;
	vec->resize = ft_vec_resize;
	vec->count = ft_vec_count;
	vec->get = ft_vec_get;
	return (vec);
}
