/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_resize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 21:55:06 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/19 16:48:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Resizes the vector
 *
 * @warning If the new size is smaller than the current size, the data
 * will be lost for the elements that are removed from the vector are
 * not freed. Watch out for memory leaks! 🚰
 *
 * @param vec The vector to resize
 * @param new_lenght The new size of the vector
 * @return void* The new data pointer or NULL when failed
 */
void	*ft_vec_resize(t_vector *vec, size_t new_lenght)
{
	void	*new;

	if (new_lenght == 0)
	{
		free(vec->data);
		vec->data = NULL;
		vec->lenght = 0;
		vec->capacity = 0;
		return (NULL);
	}
	if (new_lenght < vec->lenght)
		return (NULL);
	new = ft_realloc(vec->data, new_lenght * vec->type_size);
	if (!new)
	{
		ft_vec_free(vec, true);
		return (NULL);
	}
	vec->data = new;
	vec->capacity = new_lenght;
	return (vec->data);
}
