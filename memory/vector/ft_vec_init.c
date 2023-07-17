/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:19:09 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/17 22:13:52 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Initializes a vector
 *
 * @param vec The vector to initialize
 * @param size The initial size of the vector
 * @param type_size The size of the content of the vector
 * @return bool true when succeeded, false when failed
 */
bool	ft_vec_init(t_vector *vec, size_t size, size_t type_size)
{
	vec->data = ft_calloc(size, type_size);
	if (!vec->data)
		return (false);
	vec->size = 0;
	vec->capacity = size;
	vec->type_size = type_size;
	return (true);
}
