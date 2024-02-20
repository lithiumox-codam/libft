/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 16:33:04 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/20 15:24:18 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Writes a character to a file descriptor
 *
 * @param c The character to write
 * @param fd The file descriptor to write to
 */
void	ft_putchar_fd(const char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return ;
}
