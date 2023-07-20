/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vec_count.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/20 23:10:32 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/20 23:15:33 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**

	* @brief Counts the amount of occurences of a value in a vector using a function provided by the user
 *
 * @param vec The vector to count in
 * @param f The function to use to compare the values
 * @param value The value to compare to
 * @return size_t The amount of occurences
 */
size_t	ft_vec_count(t_vector *vec, bool (*f)(void *))
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < vec->lenght)
	{
		if (f(vec->data + i * vec->type_size))
			count++;
		i++;
	}
	return (count);
}
