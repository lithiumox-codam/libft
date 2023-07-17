/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_insert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:40:55 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:30:21 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Inserts an element into the vector
 *
 * @param v The vector to insert into
 * @param i The index to insert at
 * @param data The data to insert
 * @return bool true when succeeded, false when failed
 */
bool	ft_vec_insert(t_vector *v, size_t i, void *data)
{
	void	*new;

	if (i > v->lenght)
		return (false);
	if (v->lenght == v->capacity)
	{
		new = ft_realloc(v->data, v->capacity * 2 * v->type_size);
		if (!new)
		{
			return (false);
		}
		v->data = new;
		v->capacity *= 2;
	}
	ft_memmove(
		v->data + (i + 1) * v->type_size,
		v->data + i * v->type_size,
		(v->lenght - i) * v->type_size);
	ft_memcpy(v->data + i * v->type_size, data, v->type_size);
	v->lenght++;
	return (true);
}
