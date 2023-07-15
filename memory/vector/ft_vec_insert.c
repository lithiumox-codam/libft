/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_insert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:40:55 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/15 22:42:30 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Inserts an element into the vector
 *
 * @param v The vector to insert into
 * @param i The index to insert at
 * @param data The data to insert
 * @return bool true when succeeded, false when failed
 */
bool	ft_vec_insert(t_vector *v, size_t i, void *data)
{
	void	*new;

	if (i > v->size)
		return (false);
	new = ft_realloc(v->data, v->size + v->type_size);
	if (!new)
		return (false);
	v->data = new;
	ft_memmove(v->data + i + v->type_size, v->data + i, v->size - i);
	ft_memcpy(v->data + i, data, v->type_size);
	v->size += v->type_size;
	return (true);
}
