/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_remove.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:47:29 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/17 21:58:32 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Removes an element from the vector
 *
 * @param v The vector to remove from
 * @param i The index of the element to remove
 * @return bool true when succeeded, false when failed
 */
void	*ft_vec_remove(t_vector *v, size_t i)
{
	void	*new;

	if (i > v->size)
		return (NULL);
	new = ft_calloc(v->size * v->type_size - v->type_size, 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, v->data, i * v->type_size);
	ft_memmove(
		v->data + i * v->type_size,
		v->data + (i + 1) * v->type_size,
		(v->size - i - 1) * v->type_size);
	free(v->data);
	v->data = new;
	v->size -= v->type_size;
	return (v->data);
}
