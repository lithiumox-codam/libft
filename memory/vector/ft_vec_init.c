/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:19:09 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Initializes a vector
 *
 * @param vec The vector to initialize
 * @param capacity The initial size of the vector
 * @param type_size The size of the content of the vector
 * @return bool true when succeeded, false when failed
 */
bool	ft_vec_init(t_vector *vec, size_t capacity, size_t type_size)
{
	vec->data = ft_calloc(capacity, type_size);
	if (!vec->data)
		return (false);
	vec->size = 0;
	vec->capacity = capacity;
	vec->type_size = type_size;
	return (true);
}
