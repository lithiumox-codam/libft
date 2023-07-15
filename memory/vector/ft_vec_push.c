/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_push.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:26:05 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/15 22:38:18 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Pushes data to the end of the vector
 *
 * @param vec The vector to push to
 * @param data The data to push
 * @return bool true when succeeded, false when failed
 */
bool	ft_vec_push(t_vector *vec, void *data)
{
	void	*new;

	if (vec->size == 0)
		return (false);
	new = ft_realloc(vec->data, vec->size + vec->type_size);
	if (!new)
		return (false);
	vec->data = new;
	ft_memcpy(vec->data + vec->size, data, vec->type_size);
	vec->size += vec->type_size;
	return (true);
}
