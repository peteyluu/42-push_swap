/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:58:55 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 14:59:05 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_total(t_vec **v)
{
	int	i;
	int	hole;
	t_elem	curr;

	i = 1;
	while (i < (*v)->log_len)
	{
		curr = (*v)->arr[i];
		hole = i;
		while (hole > 0 && ((*v)->arr[hole - 1].total > curr.total || 
			((*v)->arr[hole - 1].total == curr.total && (*v)->arr[hole - 1].data > curr.data)))
		{
			(*v)->arr[hole] = (*v)->arr[hole - 1];
			hole--;
		}
		i++;
		(*v)->arr[hole] = curr;
	}
}

void	sort_pos(t_vec **v)
{
	int	i;
	int	hole;
	t_elem	curr;

	i = 1;
	while (i < (*v)->log_len)
	{
		curr = (*v)->arr[i];
		hole = i;
		while (hole > 0 && (*v)->arr[hole - 1].pos > curr.pos)
		{
			(*v)->arr[hole] = (*v)->arr[hole - 1];
			hole--;
		}
		i++;
		(*v)->arr[hole] = curr;
	}
}

void	sort_data(t_vec **v)
{
	int	i;
	int	hole;
	t_elem	curr;

	i = 1;
	while (i < (*v)->log_len)
	{
		curr = (*v)->arr[i];
		hole = i;
		while (hole > 0 && (*v)->arr[hole - 1].data > curr.data)
		{
			(*v)->arr[hole] = (*v)->arr[hole - 1];
			hole--;
		}
		i++;
		(*v)->arr[hole] = curr;
	}
}
