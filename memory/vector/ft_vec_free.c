/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:34:11 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/19 21:31:08 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Frees a vector and the data in it
 *
 * @param vec The vector to free
 * @param f The function to free the data in the vector
 */
void ft_vec_free(t_vector *vec, void (*f)(void *))
{
	size_t i;

	i = 0;
	if (f)
	{
		while (i < vec->lenght)
		{
			f(vec->data + i * vec->type_size);
			i++;
		}
	}
	free(vec->data);
	vec->data = NULL;
	vec->lenght = 0;
	vec->capacity = 0;
	vec->type_size = 0;
}
