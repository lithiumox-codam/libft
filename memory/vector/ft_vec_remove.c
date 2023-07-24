/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_remove.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:47:29 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/24 10:45:08 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Removes an element from the vector
 *
 * @param v The vector to remove from
 * @param i The index of the element to remove
 * @return void* The new vector
 *
 * @warning When freeing a struct with this function,the f function should be
 * used to free the data in the vector. If the data is not freed, a memory
 * leak willoccur. If the data doesnt need to be freed, the function can
 * be set to NULL.
 */
void	*ft_vec_remove(t_vector *v, size_t i)
{
	void	*new;

	if (i > v->lenght)
		return (NULL);
	if (v->f)
		v->f(v->data + i * v->type_size);
	new = ft_calloc(v->lenght * v->type_size - v->type_size, 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, v->data, i * v->type_size);
	ft_memmove(
		v->data + i * v->type_size,
		v->data + (i + 1) * v->type_size,
		(v->lenght - i - 1) * v->type_size);
	free(v->data);
	v->data = new;
	v->lenght--;
	return (v->data);
}
