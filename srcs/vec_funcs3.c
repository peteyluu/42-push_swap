/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_funcs3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:10:19 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 15:10:29 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_vec_ab_op(t_vec **v)
{
	int	i;

	i = 0;
	while (i < (*v)->log_len)
	{
		pop_vec_ab_op_hlpr(&(*v)->arr[i]);
		i++;
	}
}

void	pop_vec_ab_op_hlpr(t_elem *e)
{
	e->ab_op_cnt = 0;
	if (e->a_op == fra && e->b_op == frb)
	{
		e->ab_op = frr;
		while (e->a_op_cnt > 0 && e->b_op_cnt > 0)
		{
			e->ab_op_cnt++;
			e->a_op_cnt--;
			e->b_op_cnt--;
		}
	}
	else if (e->a_op == frra && e->b_op == frrb)
	{
		e->ab_op = frrr;
		while (e->a_op_cnt > 0 && e->b_op_cnt > 0)
		{
			e->ab_op_cnt++;
			e->a_op_cnt--;
			e->b_op_cnt--;
		}
	}
}

void	pop_vec_total(t_vec **v)
{
	int	i;

	i = 0;
	while (i < (*v)->log_len)
	{
		(*v)->arr[i].total = (*v)->arr[i].a_op_cnt + (*v)->arr[i].b_op_cnt + (*v)->arr[i].ab_op_cnt;
		i++;
	}
}
