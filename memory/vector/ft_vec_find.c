/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_find.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 02:41:44 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/22 16:28:20 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_found	*create_struct(void *data, size_t index)
{
	t_found	*found;

	found = malloc(sizeof(t_found));
	if (!found)
		return (NULL);
	found->item = data;
	found->index = index;
	return (found);
}

/**
 * @brief Finds the all occurences of a comparison in the vector
 *
 * @param vec The vector to search in
 * @param cmp The function to compare the data
 * @return t_found** A list of found items ending with NULL or NULL when failed
 */
t_found	**ft_vec_find(t_vector *vec, bool (*cmp)(void *))
{
	size_t	i;
	size_t	count;
	t_found	**found;

	i = 0;
	count = ft_vec_count(vec, cmp);
	found = malloc(sizeof(t_found) * (count + 1));
	if (!found || count == 0)
		return (NULL);
	while (i < vec->lenght)
	{
		if (cmp(vec->data + i * vec->type_size) == true)
		{
			found[count] = create_struct(vec->data + i * vec->type_size, i);
			if (!found[count])
				return (NULL);
			count--;
		}
		i++;
	}
	found[count] = NULL;
	return (found);
}
