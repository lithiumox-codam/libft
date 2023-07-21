/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_get.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:33:02 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/21 12:59:18 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Gets an element from the vector
 *
 * @param vec The vector to get from
 * @param index The index of the element
 * @return void* The element
 */
void	*ft_vec_get(t_vector *vec, size_t index)
{
	if (vec == NULL)
		return (NULL);
	if (index <= 0)
		return (NULL);
	if (index >= vec->lenght)
		return (NULL);
	return (vec->data + index * vec->type_size);
}
