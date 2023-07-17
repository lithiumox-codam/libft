/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 21:52:28 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/18 00:16:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Reallocates a memory space, copies it then frees the old space
 *
 * @param ptr The memory to reallocate
 * @param size The new size of the space in bytes
 * @return void* The reallocated memory or NULL when failed
 */

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	new = ft_calloc(1, size);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}
