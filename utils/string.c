/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/21 15:57:10 by mdekker       #+#    #+#                 */
/*   Updated: 2024/01/04 13:40:16 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Checks if a character is in a string
 *
 * @param c The character to check
 * @param comparison The string to check in
 * @return int 1 if the character is in the string, 0 if not
 */
int	checkchar(char c, char *comparison)
{
	if (!(*comparison))
		return (0);
	else if (c == *comparison)
		return (1);
	return (checkchar(c, comparison + 1));
}

/**
 * @brief checkchar for an entire string
 *
 * @param str The string to check
 * @param comparison The string to check in
 */
int	checkstr(char *str, char *comparison)
{
	if (!(*str))
		return (1);
	else if (checkchar(*str, comparison) == 0)
		return (0);
	return (checkstr(str + 1, comparison));
}
