/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 15:14:41 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/20 15:23:55 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Writes a string to a file descriptor, followed by a newline
 *
 * @param s The string to write
 * @param fd The file descriptor to write to
 */
void	ft_putendl_fd(const char *s, int fd)
{
	ft_putstr_fd(s, fd);
	if (write(fd, "\n", 1) == -1)
		return ;
}
