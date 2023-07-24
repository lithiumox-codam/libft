/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_remove.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker/jde-baai <team@codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:47:29 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/24 11:41:30 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Removes an element from the vector
 *
 * @param v The vector to remove from
 * @param i The index of the element to remove
 * @return void* The new vector
 */
void	*ft_vec_remove(t_vector *v, size_t i)
{
	if (i >= v->lenght)
		return (NULL);
	if (v->f)
		v->f(v->data + i * v->type_size);
	ft_memmove(
		v->data + i * v->type_size,
		v->data + (i + 1) * v->type_size,
		(v->lenght - i - 1) * v->type_size);
	v->lenght--;
	return (v->data);
}
