/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_replace_multiple.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 13:09:13 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/21 13:29:19 by mdekker       ########   odam.nl         */
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
 */
static void	replace_single_element(t_vector *vec, size_t index, void **data)
{
	ft_memcpy(vec->data + index * vec->type_size, data[0], vec->type_size);
}

static void	move_existing_elements(t_vector *vec, size_t index,
		size_t data_count)
{
	if (index + data_count <= vec->lenght)
	{
		ft_memmove(
			vec->data + (index + data_count) * vec->type_size,
			vec->data + index * vec->type_size,
			(vec->lenght - index) * vec->type_size);
	}
}

static void	copy_new_elements(t_vector *vec, size_t index, size_t data_count,
		void **data)
{
	size_t	i;

	i = 0;
	while (i < data_count)
	{
		ft_memcpy(
			vec->data + (index + i) * vec->type_size,
			data[i],
			vec->type_size);
		i++;
	}
}

static void	replace_multiple_elements(t_vector *vec, size_t index,
		size_t data_count, void **data)
{
	if (index + data_count <= vec->lenght)
	{
		ft_memmove(
			vec->data + (index + data_count) * vec->type_size,
			vec->data + index * vec->type_size,
			(vec->lenght - index) * vec->type_size);
	}
	move_existing_elements(vec, index, data_count);
	copy_new_elements(vec, index, data_count, data);
}

void	ft_vec_replace_multiple(t_vector *vec, size_t index, void **data)
{
	size_t	data_count;

	data_count = 0;
	if (vec->f)
		vec->f(vec->data + index * vec->type_size);
	while (data[data_count])
		data_count++;
	if (data_count == 0)
		return ;
	if (data_count == 1)
	{
		replace_single_element(vec, index, data);
		return ;
	}
	data_count--;
	replace_multiple_elements(vec, index, data_count, data);
}
