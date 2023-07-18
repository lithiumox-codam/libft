/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:34:11 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 12:21:42 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Frees a vector and the data in it
 *
 * @param vec The vector to free
 * @param free_data The function to free the data in the vector
 */
void	ft_vec_free(t_vector *vec, void (*free_data)(void *))
{
	size_t	i;

	i = 0;
	if (free_data)
	{
		while (i < vec->lenght)
		{
			free_data(vec->data + i * vec->type_size);
			i++;
		}
	}
	vec->data = NULL;
	vec->lenght = 0;
	vec->capacity = 0;
	vec->type_size = 0;
}
