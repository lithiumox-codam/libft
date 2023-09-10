/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec_find.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 02:41:44 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/28 17:55:30 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static bool	find_matches(t_vector *vec, bool (*cmp)(void *), t_vector *found)
{
	size_t	i;

	i = 0;
	while (i < vec->length)
	{
		if (cmp(vec->data + i * vec->type_size) == true)
			vec_push(found, vec->data + i * vec->type_size);
		i++;
	}
	return (true);
}

/**
 * @brief Finds the all occurences of a comparison in the vector
 *
 * @param vec The vector to search in
 * @param cmp The function to compare the data
 * @return t_vector* A vector of found items or NULL when failed
 */
t_vector	*vec_find(t_vector *vec, bool (*cmp)(void *))
{
	size_t		count;
	t_vector	*found;

	count = vec_count(vec, cmp);
	if (count == 0)
		return (NULL);
	found = vec_init(malloc(sizeof(t_vector)), count, vec->type_size,
			vec->free);
	if (!found)
		return (NULL);
	find_matches(vec, cmp, found);
	return (found);
}
