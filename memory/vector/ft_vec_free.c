/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:34:11 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/19 11:31:42 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Frees a vector and the data in it
 *
 * @param vec The vector to free
 * @param clear_content If true uses the free function provided to clear data
 */
void	ft_vec_free(t_vector *vec, bool clear_content)
{
	size_t	i;

	i = 0;
	if (clear_content)
	{
		while (i < vec->lenght)
		{
			vec->free_func(vec->data + i * vec->type_size);
			i++;
		}
	}
	free(vec->data);
	vec->data = NULL;
	vec->lenght = 0;
	vec->capacity = 0;
	vec->type_size = 0;
	vec->free_func = NULL;
}
