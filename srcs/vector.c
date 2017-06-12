/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:20:57 by pluu              #+#    #+#             */
/*   Updated: 2017/06/05 14:57:03 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vector_new(t_vector **ops)
{
	if (!(*ops = (t_vector*)malloc(sizeof(t_vector))))
		exit(-1);
	(*ops)->log_len = 0;
	(*ops)->alloc_len = 4;
	if (!((*ops)->arr = (int*)malloc(sizeof(int) * (*ops)->alloc_len)))
		exit(-1);
}

void	vector_add(t_vector **ops, int elem)
{
	if ((*ops)->log_len == (*ops)->alloc_len)
		vector_grow(ops);
	(*ops)->arr[(*ops)->log_len] = elem;
	(*ops)->log_len++;
}

void	vector_grow(t_vector **ops)
{
	int	*tmp;
	int	i;

	(*ops)->alloc_len *= 2;
	if (!(tmp = (int*)malloc(sizeof(int) * (*ops)->alloc_len)))
		exit(-1);
	i = 0;
	while (i < (*ops)->log_len)
	{
		tmp[i] = (*ops)->arr[i];
		i++;
	}
	free((*ops)->arr);
	(*ops)->arr = tmp;
}

void	vector_dispose(t_vector **ops)
{
	if (!*ops)
		return ;
	free((*ops)->arr);
	free(*ops);
}

void	vector_print(t_vector *ops)
{
	int	i;

	i = 0;
	while (i < ops->log_len)
	{
		ft_printf("%d\n", ops->arr[i]);
		i++;
	}
}
