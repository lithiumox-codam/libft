/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_find.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 21:29:04 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/17 23:49:52 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the first occurence of data in the vector
 *
 * @param vec The vector to search in
 * @param data The data to search for
 * @param cmp The function to compare the data
 * @return size_t The index of the first occurence, or -1 when not found
 */

size_t	ft_vec_find(t_vector *vec, void *data, int (*cmp)(void *, void *))
{
	size_t	i;

	i = -1;
	while (i < vec->size)
		if (cmp(vec->data + i * vec->type_size, data) == 0)
			return (i);
	return (-1);
}
