/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/05 16:24:01 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/20 15:23:44 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Writes a string to a file descriptor
 *
 * @param s The string to write
 * @param fd The file descriptor to write to
 */
void	ft_putstr_fd(const char *s, int fd)
{
	if (write(fd, s, ft_strlen(s)) == -1)
		return ;
}
