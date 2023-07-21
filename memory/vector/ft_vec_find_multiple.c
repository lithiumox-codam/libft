/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_find_multiple.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 02:41:44 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/21 02:43:51 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Finds the all occurences of a comparison in the vector
 *
 * @param vec The vector to search in
 * @param cmp The function to compare the data
 * @return void* The found data, or NULL if not found
 */
void	**ft_vec_find_multiple(t_vector *vec, bool (*cmp)(void *))
{
	size_t	i;
	size_t	count;
	void	**found;

	i = 0;
	count = ft_vec_count(vec, cmp);
	found = malloc(sizeof(void *) * (count + 1));
	if (!found || count == 0)
		return (NULL);
	while (i < vec->lenght)
	{
		if (cmp(vec->data + i * vec->type_size) == true)
		{
			found[count] = vec->data + i * vec->type_size;
			count--;
		}
		i++;
	}
	return (found);
}
