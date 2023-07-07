/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   Created: 2023/05/21 11:52:58 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/07 23:25:12 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Gets the numbers behind the decimal
 *
 * @param str The left over numbers behind the dot
 * @param decimal The decimal to add the numbers to
 * @return char* The string representation of the integer
 */
static void	ft_get_decimal(char *str, double *decimal)
{
	double	factor;

	factor = 1;
	if (*str == '.')
		str++;
	while (*str)
	{
		*decimal = *decimal * 10 + (*str - '0');
		factor *= 10;
		str++;
	}
	*decimal /= factor;
	ft_printf("decimal: %f\n", *decimal);
}

/**
 * @brief Converts a string to a double
 *
 * @param str The string to convert
 *
 * @return double The converted string
 */
double	ft_atod(char *str)
{
	double	result;
	double	decimal;
	int		sign;

	result = 0;
	decimal = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	ft_get_decimal(str, &decimal);
	decimal /= ft_pow(10, ft_intlen((int)decimal));
	return (sign * (result + decimal));
}
