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

static t_found	*create_found_item(void *item, size_t index)
{
	t_found	*found_item;

	found_item = (t_found *)malloc(sizeof(t_found));
	if (!found_item)
		return (NULL);
	found_item->item = item;
	found_item->index = index;
	return (found_item);
}

static bool	find_matches(t_vector *vec, bool (*cmp)(void *), t_vector *found)
{
	size_t	i;
	t_found	*found_item;

	i = 0;
	while (i < vec->length)
	{
		if (cmp(vec->data + i * vec->type_size) == true)
		{
			found_item = create_found_item(vec->data + i * vec->type_size, i);
			if (!found_item)
				return (false);
			vec_push(found, found_item);
		}
		i++;
	}
	return (true);
}

/**
 * @brief The function to free the found data struct not the data itself
 *
 * @param item The found data struct
 */
static void	free_found(void *item)
{
	free(item);
}

/**
 * @brief Finds the all occurences of a comparison in the vector
 *
 * @param vec The vector to search in
 * @param cmp The function to compare the data
 * @return t_vector* of t_found structs with the found data or NULL on error
 */
t_vector	*vec_find(t_vector *vec, bool (*cmp)(void *))
{
	size_t		count;
	t_vector	*found;

	count = vec_count(vec, cmp);
	if (count == 0)
		return (NULL);
	found = vec_init(malloc(sizeof(t_vector)), count, sizeof(t_found),
			free_found);
	if (!found)
		return (NULL);
	if (!find_matches(vec, cmp, found))
		return (vec_free(found), NULL);
	return (found);
}
