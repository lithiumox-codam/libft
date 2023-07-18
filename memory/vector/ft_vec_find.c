/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_find.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/17 21:29:04 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 21:50:18 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Finds the first occurence of data in the vector
 *
 * @param vec The vector to search in
 * @param data The data to search for
 * @param cmp The function to compare the data
 * @return void* The found data, or NULL if not found
 */

void	*ft_vec_find(t_vector *vec, void *data, int (*cmp)(void *, void *))
{
	size_t	i;

	i = 0;
	while (i < vec->lenght)
	{
		if (cmp(vec->data + i * vec->type_size, data) == 0)
			return (vec->data + i * vec->type_size);
		i++;
	}
	return (NULL);
}
