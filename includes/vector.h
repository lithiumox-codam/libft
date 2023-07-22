/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 22:20:37 by mdekker       #+#    #+#                 */
/*   Updated: 2023/07/22 16:38:07 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>
# include <stdlib.h>

/**
 * @brief A struct to store the found data and index so it can be returned
 *
 * @param item The found data
 * @param index The index of the found data
 *
 * @note This struct is only used in ft_vec_find so the user doesn't have to
 * call the other functions to get the index of the found data
 */
typedef struct s_found
{
	void	*item;
	size_t	index;
}			t_found;

/**
 * @brief A vector struct
 *
 * @param data The data of the vector
 * @param lenght The current lenght of the vector
 * @param type_size The size of the content of the vector
 * @param capacity The current capacity of the vector
 * @param f The function to free the data of the vector
 * @param find The function to find data in the vector
 * @param apply The function to apply a function to all data in the vector
 * @param pop The function to pop the last element of the vector
 * @param remove The function to remove an element from the vector
 * @param insert The function to insert an element in the vector
 * @param push The function to push an element to the vector
 * @param resize The function to resize the vector
 * @param count The function to count the amount of occurences of a value
 * @param get The function to get an element from the vector
 * @return void
 *
 */
typedef struct s_vector
{
	void	*data;
	size_t	lenght;
	size_t	type_size;
	size_t	capacity;
	void	(*f)(void *);
	t_found	**(*find)(struct s_vector *, bool (*)(void *));
	void	(*apply)(struct s_vector *, void (*)(void *));
	void	*(*pop)(struct s_vector *);
	void	*(*remove)(struct s_vector *, size_t, void (*)(void *));
	bool	(*insert)(struct s_vector *, size_t, void *);
	bool	(*push)(struct s_vector *, void *);
	bool	(*resize)(struct s_vector *, size_t);
	size_t	(*count)(struct s_vector *, bool (*)(void *));
	void	*(*get)(struct s_vector *, size_t);
	void	*(*set)(struct s_vector *, size_t, void *);
	void	*(*replace)(struct s_vector *, size_t, void **);
}			t_vector;

void		*ft_vec_init(t_vector *vec, size_t capacity, size_t type_size,
				void (*free)(void *));
void		*ft_vec_get(t_vector *vec, size_t index);
void		*ft_vec_set(t_vector *vec, size_t index, void *data);
void		*ft_vec_pop(t_vector *vec);
void		*ft_vec_remove(t_vector *v, size_t i, void (*f)(void *));
t_found		**ft_vec_find(t_vector *vec, bool (*cmp)(void *));
void		*ft_vec_replace(t_vector *vec, size_t index, void **data);
void		ft_vec_apply(t_vector *vec, void (*f)(void *));
void		ft_vec_free(t_vector *vec);
bool		ft_vec_insert(t_vector *v, size_t i, void *data);
bool		ft_vec_push(t_vector *vec, void *data);
bool		ft_vec_resize(t_vector *vec, size_t new_size);
size_t		ft_vec_count(t_vector *vec, bool (*f)(void *));

#endif
