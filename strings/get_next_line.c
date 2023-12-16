/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 23:39:37 by mdekker       #+#    #+#                 */
/*   Updated: 2023/12/17 00:03:39 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Use the vector lib to concat the line
 *
 * @param line
 * @param buff
 * @param bufflen
 * @return char*
 */
static bool	concat(t_gnl *buff)
{
	int	i;

	i = 0;
	while (i < buff->length && buff->buffer[i] != '\n')
	{
		if (!vec_char_push(&buff->line, buff->buffer[i]))
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Gets the line from the vector and returns it as a string.
 *
 * @param buffer The vector to get the line from.
 * @return char* The line as a string.
 */
static char	*return_line(t_gnl *buffer)
{
	if (vec_resize(&buffer->line, buffer->line.length + 1))
		return (free(&buffer->line.data), NULL);
	if (vec_char_push(&buffer->line, '\0'))
		return (free(&buffer->line.data), NULL);
	return ((char *)buffer->line.data);
}

/**
 * @brief Get the remaining buff object by copying the remaining buffer to the
 * beginning of the buffer. This is done so that the next time the function is
 * called, the buffer will be read from the beginning.
 *
 * @param buffer The buffer to get the remaining buffer from.
 */
static void	get_remaining_buff(t_gnl *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (i < buffer->length && buffer->buffer[i] != '\n')
		i++;
	if (i < buffer->length)
		i++;
	j = 0;
	while (i < buffer->length)
	{
		buffer->buffer[j] = buffer->buffer[i];
		i++;
		j++;
	}
	buffer->length = j;
}

/**
 * @brief Reads the line from the file descriptor.
 *
 * @param buffer The buffer to read into.
 * @param fd The file descriptor to read from.
 * @return true The line was read.
 * @return false There was an error.
 */
static bool	read_line(t_gnl *buffer, int fd)
{
	bool	found;

	found = false;
	while (buffer->length > 0 && !found)
	{
		buffer->length = read(fd, buffer->buffer, BUFFER_SIZE);
		if (buffer->length == 0)
			break ;
		if (buffer->length < 0)
		{
			free(buffer->line.data);
			return (false);
		}
		if (!concat(buffer))
			return (false);
		if (ft_lstrchr(buffer->buffer, '\n', buffer->length))
			found = true;
		get_remaining_buff(buffer);
	}
	return (true);
}

/**
 * @brief get_next_line function that reads from a file descriptor and
 * returns the next line. It uses a static buffer to store the remaining buffer
 * and a vector to store the line. The vector is used to store the line because
 * it can be resized easily.
 *
 * @param fd The file descriptor to read from.
 * @return char* The next line. Or NULL if there was an error.
 */
char	*get_next_line(int fd)
{
	static t_gnl	buffer;

	if (!vec_init(&buffer.line, VEC_SIZE, sizeof(char), NULL))
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer.length > 0)
	{
		if (ft_lstrchr(buffer.buffer, '\n', buffer.length))
		{
			if (!concat(&buffer))
				return (free(&buffer.line.data), NULL);
			get_remaining_buff(&buffer);
			return (return_line(&buffer));
		}
		else
		{
			if (!concat(&buffer))
				return (free(buffer->line.data), NULL);
			buffer.length = 0;
		}
	}
	if (!read_line(&buffer, fd))
		return (free(&buffer->line.data), NULL);
	return (return_line(&buffer));
}
