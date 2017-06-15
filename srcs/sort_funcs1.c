/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:58:36 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 14:58:49 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_node *s1, t_node *s2)
{
	if (stack_empty(s1) || !stack_empty(s2))
		return (0);
	while (s1 && s1->next)
	{
		if (s1->data < s1->next->data)
			return (0);
		s1 = s1->next;
	}
	return (1);
}

int	is_sort_sa(t_node *s1)
{
	if (stack_empty(s1))
		return (0);
	while (s1 && s1->next)
	{
		if (s1->data < s1->next->data)
			return (0);
		s1 = s1->next;
	}
	return (1);
}

void	init_issort_vars(t_sort *vars, t_vec *v, t_node *s)
{	
	vars->i = 0;
	vars->j = v->log_len - 1;
	vars->min = stack_min(s);
	vars->max = stack_max(s);
	vars->decr = 0;
	vars->incr = 0;
}

int	is_sort_stack(t_vec *v, t_node *s)
{
	t_sort	vars;

	init_issort_vars(&vars, v, s);
	while (vars.i < vars.j)
	{
		if (v->arr[vars.i].data == vars.max && v->arr[vars.i + 1].data == vars.min)
		{
			vars.decr = 0;
			vars.incr = 1;
		}
		else if (v->arr[vars.i].data == vars.min && v->arr[vars.i + 1].data == vars.max)
		{
			vars.decr = 1;
			vars.incr = 0;
		}
		else if (v->arr[vars.i].data > v->arr[vars.i + 1].data)
			vars.decr = 1;	
		else if (v->arr[vars.i + 1].data > v->arr[vars.i].data)
			vars.incr = 1;
		if (vars.decr && vars.incr)
			return (0);
		vars.i++;
	}
	return (((vars.decr && !vars.incr) || (!vars.decr && vars.incr)) ? 1 : 0);
}

void	sort_ascend(t_stacks **s, t_vecs **v)
{
	vec_dispose(&(*v)->s1);
	init_vec(&(*v)->s1, stack_len((*s)->s1));
	pop_vec(&(*v)->s1, (*s)->s1);
	handle_top_min1(s, v, stack_min((*s)->s1));
}

