/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_funcs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:09:43 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 15:09:56 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_vec_a_top(t_vec **v, t_node *s)
{
	int	i;

	i = 0;
	while (i < (*v)->log_len)
	{
		get_vec_a_top(&(*v)->arr[i], s);
		i++;
	}
}

void	get_vec_a_top(t_elem *e, t_node *s)
{
	int	top;
	int	bot;

	top = e->pos;
	bot = ft_abs(e->pos - stack_len(s));
	if (!top)
	{
		e->a_op_cnt = top;
		e->a_op = fn;
	}
	else if (top < bot)
	{
		e->a_op_cnt = top;
		e->a_op = fra;
	}
	else
	{
		e->a_op_cnt = bot;
		e->a_op = frra;
	}
}

void	pop_vec_b_sort(t_vecs **v, t_node *s)
{
	int	i;

	i = 0;
	while (i < (*v)->s1->log_len)
	{
		get_b_sort((*v)->s2, s, &(*v)->s1->arr[i]);
		i++;
	}
}

void	get_b_sort(t_vec *v, t_node *s, t_elem *e)
{
	t_gbs	vars;

	vars.min = stack_min(s);
	vars.max = stack_max(s);
	vars.len = stack_len(s) - 1;
	if (e->data > vars.max || e->data < vars.min)
	{
		vars.tmp = v->arr[get_elem(v, vars.max)];
		vars.top = vars.tmp.pos;
		vars.bot = ft_abs(vars.tmp.pos - vars.len) + 1;
	}
	else
	{
		vars.tmp = v->arr[get_elem2(v, e->data)];
		vars.top = vars.tmp.pos;
		vars.bot = ft_abs(vars.tmp.pos - vars.len) + 1;
	}
	get_b_sort_hlpr(e, vars);
}

void	get_b_sort_hlpr(t_elem *e, t_gbs vars)
{
	vars.tmp1 = (e->a_op_cnt + vars.top) / 2;
	vars.tmp2 = (e->a_op_cnt + vars.bot) / 2;
	if (e->a_op == fra || e->a_op == frra)
	{
		if (vars.tmp1 < vars.tmp2 || (vars.top == vars.bot && e->a_op == fra))
		{
			e->b_op_cnt = vars.top;
			e->b_op = frb;
		}
		else
		{
			e->b_op_cnt = vars.bot;
			e->b_op = frrb;
		}
	}
	else if (vars.top < vars.bot)
	{
		e->b_op_cnt = vars.top;
		e->b_op = frb;
	}
	else
	{
		e->b_op_cnt = vars.bot;
		e->b_op = frrb;
	}
}
