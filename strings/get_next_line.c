/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/16 23:39:37 by mdekker       #+#    #+#                 */
/*   Updated: 2024/02/01 18:54:53 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

/**
 * @brief A wrapper for vec_char_push so it pushes until a newline is found.
 *
 * @param line The vector to push to.
 * @param buff The buffer to push from.
 * @param length The length of the buffer.
 * @return true When succeeded.
 * @return false When failed.
 */
static bool	push_until_nl(t_vector *line, char *buff, int length)
{
	int	i;

	i = 0;
	while (i < length && buff[i] != '\n')
	{
		if (!vec_char_push(line, buff[i]))
			return (false);
		i++;
	}
	if (buff[i] == '\n')
	{
		if (!vec_char_push(line, buff[i]))
			return (false);
	}
	return (true);
}

/**
 * @brief A wrapper for vec_resize so it returns the vector in
 * the form of a char*.
 *
 * @param line The vector to resize.
 * @return char* The vector in the form of a char*. NULL when failed.
 */
static char	*resize_and_return(t_vector *line)
{
	if (line->length == 0)
		return (free(line->data), NULL);
	if (!vec_resize(line, line->length + 1))
		return (free(line->data), NULL);
	vec_char_push(line, '\0');
	return ((char *)line->data);
}

/**
 * @brief Get the remaining buffer if a newline is found.
 *
 * @note This function is only called when a newline is found in the buffer. And
 * the remaining buffer is put in the beginning of the buffer. This is done so
 * the next call to get_next_line it will read the remaining buffer first.
 *
 * @param buffer The struct containing the buffer.
 */
static void	get_remaining_buff(t_gnl *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (i < buffer->length && buffer->buff[i] != '\n')
		i++;
	if (i < buffer->length)
		i++;
	j = 0;
	while (i < buffer->length)
	{
		buffer->buff[j] = buffer->buff[i];
		i++;
		j++;
	}
	buffer->length = j;
}

/**
 * @brief A wrapper for read() so it modifies the variables in the struct.
 *
 * @param buffer The struct containing the buffer.
 * @param line The line read from the file descriptor.
 * @param fd The file descriptor to read from.
 * @return char* The line read from the file descriptor.
 */
static bool	read_line(t_gnl *buffer, t_vector *line, int fd)
{
	bool	found;

	found = false;
	while (!found)
	{
		buffer->length = read(fd, buffer->buff, BUFFER_SIZE);
		if (buffer->length == 0)
			break ;
		if (buffer->length < 0)
		{
			free(line->data);
			return (false);
		}
		if (!push_until_nl(line, buffer->buff, buffer->length))
			return (false);
		if (ft_lstrchr(buffer->buff, '\n', buffer->length))
			found = true;
		get_remaining_buff(buffer);
	}
	return (true);
}

/**
 * @brief get_next_line reads a line from a file descriptor and returns it.
 *
 * @param fd The file descriptor to read from.
 * @return char* The line read from the file descriptor.
 */
char	*get_next_line(int fd)
{
	static t_gnl	buffer;
	t_vector		line;

	if ((fd < 0 || BUFFER_SIZE <= 0) || !vec_init(&line, BUFFER_SIZE,
			sizeof(char), NULL))
		return (NULL);
	if (buffer.length > 0)
	{
		if (ft_lstrchr(buffer.buff, '\n', buffer.length))
		{
			if (!push_until_nl(&line, buffer.buff, buffer.length))
				return (NULL);
			get_remaining_buff(&buffer);
			return (resize_and_return(&line));
		}
		else
		{
			if (!push_until_nl(&line, buffer.buff, buffer.length))
				return (NULL);
			buffer.length = 0;
		}
	}
	if (!read_line(&buffer, &line, fd))
		return (NULL);
	return (resize_and_return(&line));
}
