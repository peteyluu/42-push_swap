/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:40:57 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 14:41:12 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exe_elem(t_elem e, t_stacks **s, t_vector **ops)
{
	while (e.ab_op_cnt--)
	{
		exe_op(s, e.ab_op);
		vector_add(ops, e.ab_op);
		display(*s, e.ab_op);
	}
	while (e.a_op_cnt--)
	{
		exe_op(s, e.a_op);
		vector_add(ops, e.a_op);
		display(*s, e.a_op);
	}
	while (e.b_op_cnt--)
	{
		exe_op(s, e.b_op);
		vector_add(ops, e.b_op);
		display(*s, e.b_op);
	}
	exe_op(s, fpb);
	vector_add(ops, fpb);
	display(*s, fpb);
}

void	exe_op(t_stacks **s, int op)
{
	if (op == fpb)
		pb(&(*s)->s1, &(*s)->s2);
	else if (op == fra)
		ra(&(*s)->s1);
	else if (op == frb)
		rb(&(*s)->s2);
	else if (op == frra)
		rra(&(*s)->s1);
	else if (op == frrb)
		rrb(&(*s)->s2);
	else if (op == frr)
		rr(&(*s)->s1, &(*s)->s2);
	else
		rrr(&(*s)->s1, &(*s)->s2);
}

void	ops_print(t_vector *ops)
{
	int	i;

	i = -1;
	while (++i < ops->log_len)
	{
		if (ops->arr[i] == fsa)
			ft_putstr("sa\n");
		else if (ops->arr[i] == fsb)
			ft_putstr("sb\n");
		else if (ops->arr[i] == fpa)
			ft_putstr("pa\n");
		else if (ops->arr[i] == fpb)
			ft_putstr("pb\n");
		else if (ops->arr[i] == fra)
			ft_putstr("ra\n");
		else if (ops->arr[i] == frb)
			ft_putstr("rb\n");
		else if (ops->arr[i] == frr)
			ft_putstr("rr\n");
		else if (ops->arr[i] == frra)
			ft_putstr("rra\n");
		else if (ops->arr[i] == frrb)
			ft_putstr("rrb\n");
		else if (ops->arr[i] == frrr)
			ft_putstr("rrr\n");
	}
}
