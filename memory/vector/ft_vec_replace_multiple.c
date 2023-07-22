/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_replace_multiple.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 13:09:13 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/22 16:19:33 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Replaces one element in the vector and frees it then proceeds to
 * replace it with one or more elements provided by data
 *
 * @param vec The vector to replace in
 * @param index The index of the element to replace
 * @param data The data to replace with (can be multiple elements)
 *
 * @return void* The pointer to the first element of the replaced data
 * or NULL if the replacement failed
 *
 * @note The data must be NULL terminated and the vector must be able to
 * contain the data that is being inserted
 */
void	*ft_vec_replace(t_vector *vec, size_t index, void **data)
{
	size_t	data_count;
	size_t	i;

	data_count = 0;
	if (vec->f)
		vec->f(vec->data + index * vec->type_size);
	while (data[data_count])
		data_count++;
	if (data_count == 0)
		return (NULL);
	if (data_count == 1)
	{
		ft_vec_set(vec, index, data[0]);
		return (vec->data + index * vec->type_size);
	}
	data_count--;
	i = 0;
	while (i < data_count)
	{
		if (!ft_vec_insert(vec, index + i, data[i]))
			return (NULL);
		i++;
	}
	vec->lenght += data_count;
	return (vec->data + index * vec->type_size);
}
