/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:19:09 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/22 16:38:19 by mdekker       ########   odam.nl         */
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
void	*vec_init(t_vector *vec, size_t capacity, size_t type_size,
		void (*free_data)(void *))
{
	vec->data = malloc(capacity * type_size);
	if (!vec->data)
		return (NULL);
	vec->length = 0;
	vec->capacity = capacity;
	vec->type_size = type_size;
	vec->f = free_data;
	vec->find = vec_find;
	vec->apply = vec_apply;
	vec->pop = vec_pop;
	vec->remove = vec_remove;
	vec->insert = vec_insert;
	vec->push = vec_push;
	vec->resize = vec_resize;
	vec->count = vec_count;
	vec->get = vec_get;
	vec->set = vec_set;
	vec->replace = vec_replace;
	return (vec);
}
