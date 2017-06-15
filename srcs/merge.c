/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:28:45 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 14:42:31 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_merge_vars(t_merge *vars, t_stacks *s)
{
	vars->s1_min = stack_min(s->s1);
	vars->s1_max = stack_max(s->s1);
	vars->s1_top = stack_peek(s->s1);
	vars->s1_top_next = stack_next_peek(s->s1);
	vars->s2_top = stack_peek(s->s2);	
}

void	merge(t_stacks **s, t_vecs **v)
{
	t_merge	vars;

	while (!stack_empty((*s)->s2))
	{
		init_merge_vars(&vars, *s);
		if (!is_adj_max_min((*s)->s1, (*v)->s1) && !is_sort_sa((*s)->s1))
		{
			handle_adj_max_min(s, v, vars.s1_min);
			continue ;
		}
		else if (vars.s2_top > vars.s1_max || vars.s2_top < vars.s1_min)
			handle_top_min1(s, v, vars.s1_min);
		else if ((vars.s2_top < vars.s1_top && vars.s2_top < (*s)->s1->data)
			|| vars.s2_top > vars.s1_top)
			merge_hlpr1(s, v, vars.s2_top);
		pa(&(*s)->s1, &(*s)->s2);
		vector_add(&(*v)->ops, fpa);
		display(*s, fpa);
		vec_dispose(&(*v)->s1);
		vec_dispose(&(*v)->s2);
		pop_vec_stacks(v, *s);
		sort_pos(&(*v)->s1);
	}
}

void	merge_hlpr1(t_stacks **s, t_vecs **v, int s2_top)
{
	int	i;
	t_elem	tmp;

	sort_data(&(*v)->s1);
	i = get_elem1((*v)->s1, s2_top);
	tmp = (*v)->s1->arr[i];
	handle_data_top(s, v, tmp);
}

int	is_adj_max_min(t_node *s, t_vec *v)
{
	t_iamm	vars;

	vars.min = stack_min(s);
	vars.max = stack_max(s);
	vars.idx_max = get_elem(v, vars.max);
	vars.j = v->log_len - 1;
	if ((vars.idx_max + 1) <= vars.j)
	{
		if (v->arr[vars.idx_max + 1].data == vars.min)
			return (1);
	}
	else if (vars.idx_max == vars.j)
	{
		vars.idx_min = get_elem(v, vars.min);
		if (!v->arr[vars.idx_min].pos)
			return (1);
	}
	return (0);
}

void	handle_adj_max_min(t_stacks **s, t_vecs **v, int data)
{
	handle_top_min(s, v, data);
	sa(&(*s)->s1);
	upd_pos_sa(&(*v)->s1);
	sort_pos(&(*v)->s1);
	vector_add(&(*v)->ops, fsa);
	display(*s, fsa);
}
