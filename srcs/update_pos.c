/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 13:34:06 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 13:34:16 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	upd_pos_ra(t_vec **v, int j)
{
	int	i;

	i = 0;
	while (i < (*v)->log_len)
	{
		if ((*v)->arr[i].pos == 0)
			(*v)->arr[i].pos = j;
		else
			(*v)->arr[i].pos--;
		i++;
	}
}

void	upd_pos_rra(t_vec **v, int j)
{
	int	i;

	i = 0;
	while (i < (*v)->log_len)
	{
		if ((*v)->arr[i].pos == j)
			(*v)->arr[i].pos = 0;
		else
			(*v)->arr[i].pos++;
		i++;
	}
}

void	upd_pos_sa(t_vec **v)
{
	int	tmp;

	tmp = (*v)->arr[0].pos;
	(*v)->arr[0].pos = (*v)->arr[1].pos;
	(*v)->arr[1].pos = tmp; 	
}
