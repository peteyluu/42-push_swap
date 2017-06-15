/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:43:05 by pluu              #+#    #+#             */
/*   Updated: 2017/06/14 18:05:33 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*s;
	t_vecs		*v;

	init_stacks(&s);
	init_vecs(&v);
	if (argc == 1)
		return (0);
	if (!get_check_stack(argc, argv, &s))
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else if (!is_sort(s->s1, s->s2))
		solve_ps(&s, &v);
	vecs_dispose(&v);
	stacks_dispose(&s);
	return (0);
}

void	solve_ps(t_stacks **s, t_vecs **v)
{
	int	len;

	display(*s, fn);
	len = stack_len((*s)->s1);
	vector_new(&(*v)->ops);
	handle_beg_sa(s, v);
	if (len <= THREE)
		sort_three(s, &(*v)->ops);		
	else if (len <= FIVE)
		sort_five(s, v);
	else
		sort_rand(s, v);
	if (!(*s)->v_flag && !(*s)->c_flag)
		ops_print((*v)->ops);
}

void	sort_three(t_stacks **s, t_vector **v)
{
	int	max;
	int	top;
	int	bot;

	max = stack_max((*s)->s1);
	top = stack_peek((*s)->s1);
	bot = (*s)->s1->data;
	while (!is_sort_sa((*s)->s1))
	{
		while (top < bot && !is_sort_sa((*s)->s1))
		{
			rra(&(*s)->s1);
			vector_add(v, frra);
			display(*s, frra);
			sa(&(*s)->s1);
			display(*s, fsa);
			vector_add(v, fsa);
			top = stack_peek((*s)->s1);
			bot = (*s)->s1->data;
		}
		while (top > bot)
		{
			rra(&(*s)->s1);
			vector_add(v, frra);
			display(*s, frra);
			top = stack_peek((*s)->s1);
			bot = (*s)->s1->data;
		}
	}
}

void	sort_five(t_stacks **s, t_vecs **v)
{
	handle_beg_pb(s, v);
	pop_vec_stacks(v, *s);
	sort_pos(&(*v)->s1);
	if (is_sort_stack((*v)->s1, (*s)->s1))
		merge(s, v);
	if (!is_sort_sa((*s)->s1))
		sort_ascend(s, v);
}

void	sort_rand(t_stacks **s, t_vecs **v)
{
	handle_beg_pb(s, v);
	pop_vec_stacks(v, *s);
	sort_pos(&(*v)->s1);
	while (!is_sort_stack((*v)->s1, (*s)->s1) || (*v)->s1->log_len >= FOUR)
	{
		pop_vec_a_top(&(*v)->s1, (*s)->s1);
		sort_data(&(*v)->s2);
		pop_vec_b_sort(v, (*s)->s2);
		pop_vec_ab_op(&(*v)->s1);
		pop_vec_total(&(*v)->s1);
		sort_total(&(*v)->s1);
		exe_elem((*v)->s1->arr[0], s, &(*v)->ops);
		vec_dispose(&(*v)->s1);
		vec_dispose(&(*v)->s2);
		pop_vec_stacks(v, *s);
		sort_pos(&(*v)->s1);
	}
	if (is_sort_stack((*v)->s1, (*s)->s1))
	{
		handle_top_max(s, v, stack_max((*s)->s2));
		merge(s, v);
	}
	if (!is_sort_sa((*s)->s1))
		sort_ascend(s, v);
}

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
	else if (op == frrr)
		rrr(&(*s)->s1, &(*s)->s2);
}

void	sort_ascend(t_stacks **s, t_vecs **v)
{
	vec_dispose(&(*v)->s1);
	init_vec(&(*v)->s1, stack_len((*s)->s1));
	pop_vec(&(*v)->s1, (*s)->s1);
	handle_top_min1(s, v, stack_min((*s)->s1));
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
		else if ((vars.s2_top < vars.s1_top && vars.s2_top < (*s)->s1->data) || vars.s2_top > vars.s1_top)
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

void	handle_data_top(t_stacks **s, t_vecs **v, t_elem e)
{
	int	top;
	int	bot;

	top = e.pos;
	bot = ft_abs(e.pos - (stack_len((*s)->s1) - 1)) + 1;
	if (top < bot)
	{
		while (top--)
		{
			ra(&(*s)->s1);
			vector_add(&(*v)->ops, fra);
			display(*s, fra);
		}
	}
	else
	{
		while (bot--)
		{
			rra(&(*s)->s1);
			vector_add(&(*v)->ops, frra);
			display(*s, frra);
		}
	}
}

/* checks if the [max, min] is adjacent in the desired order */
int	is_adj_max_min(t_node *s, t_vec *v)
{
	t_is_adj_max_min  vars;

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

void	handle_top_min1(t_stacks **s, t_vecs **v, int data)
{
	t_hand_top	vars;

	vars.tmp = (*v)->s1->arr[get_elem((*v)->s1, data)];
	vars.top = vars.tmp.pos;
	vars.bot = ft_abs(vars.tmp.pos - ((*v)->s1->log_len -1)) + 1;
	if (vars.top < vars.bot)
	{
		while (vars.top--)
		{
			ra(&(*s)->s1);
			vector_add(&(*v)->ops, fra);
			display(*s, fra);
		}
	}
	else
	{
		while (vars.bot--)
		{
			rra(&(*s)->s1);
			vector_add(&(*v)->ops, frra);
			display(*s, frra);
		}
	}
}

void	handle_top_max(t_stacks **s, t_vecs **v, int data)
{
	t_hand_top 	vars;

	vars.len = stack_len((*s)->s2) - 1;
	vars.tmp = (*v)->s2->arr[get_elem((*v)->s2, data)];
	vars.top = 0;
	if (vars.tmp.pos)
		vars.top = vars.tmp.pos;
	vars.bot = ft_abs(vars.tmp.pos - ((*v)->s2->log_len - 1)) + 1;
	handle_top_max_hlpr(s, v, vars);
}

void	handle_top_max_hlpr(t_stacks **s, t_vecs **v, t_hand_top vars)
{
	if (vars.top < vars.bot)
	{
		while (vars.top--)
		{
			rb(&(*s)->s2);
			vector_add(&(*v)->ops, frb);
			display(*s, frb);
		}
	}
	else
	{
		while (vars.bot--)
		{
			rrb(&(*s)->s2);
			vector_add(&(*v)->ops, frrb);
			display(*s, frrb);
		}
	}
}

void	handle_top_min(t_stacks **s, t_vecs **v, int data)
{
	t_hand_top	vars;

	vars.len = stack_len((*s)->s1) - 1;
	vars.tmp = (*v)->s1->arr[get_elem((*v)->s1, data)];
	vars.top = 0;
	if (vars.tmp.pos)
		vars.top = vars.tmp.pos;
	vars.bot = ft_abs(vars.tmp.pos - ((*v)->s1->log_len - 1)) + 1;
	handle_top_min_hlpr(s, v, vars);
	sort_pos(&(*v)->s1);
}

void	handle_top_min_hlpr(t_stacks **s, t_vecs **v, t_hand_top vars)
{
	if (vars.top < vars.bot)
	{
		while (vars.top--)
		{
			ra(&(*s)->s1);
			upd_pos_ra(&(*v)->s1, vars.len);
			vector_add(&(*v)->ops, fra);
			display(*s, fra);
		}
	}
	else
	{
		while (vars.bot--)
		{
			rra(&(*s)->s1);
			upd_pos_rra(&(*v)->s1, vars.len);
			vector_add(&(*v)->ops, frra);
			display(*s, frra);
		}
	}
}

/* get_elem2 -> returns (idx - 1) when curr.data > target */
int	get_elem2(t_vec *v, int target)
{
	int	i;

	i = 0;
	while (i < v->log_len)
	{
		if (v->arr[i].data > target)
			return (--i);
		i++;
	}
	return (-1);
}

/* get_elem1 -> returns (idx) when curr.data > target */
int	get_elem1(t_vec *v, int target)
{
	int	i;

	i = 0;
	while (i < v->log_len)
	{
		if (v->arr[i].data > target)
			return (i);
		i++;
	}
	return (-1);
}

/* get_elem -> returns idx of tha target */
int	get_elem(t_vec *v, int target)
{
	int	i;

	i = 0;
	while (i < v->log_len)
	{
		if (v->arr[i].data == target)
			return (i);
		i++;
	}
	return (-1);
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

/* 23 lines. is sorted -> if min_max or max_min is adjacent to each other (weird positioning) */
int	is_sort_stack(t_vec *v, t_node *s)
{
	t_is_sort_s vars;

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

/* insertion sort by total */
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

/* insertion sort by pos */
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

/* insertion sort by data */
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

void	handle_beg_sa(t_stacks **s, t_vecs **v)
{
	if (stack_peek((*s)->s1) > stack_next_peek((*s)->s1))
	{
		sa(&(*s)->s1);
		vector_add(&(*v)->ops, fsa);
		display(*s, fsa);
	}
}

void	handle_beg_pb(t_stacks **s, t_vecs **v)
{
	pb(&(*s)->s1, &(*s)->s2);
	vector_add(&(*v)->ops, fpb);
	display(*s, fpb);
	pb(&(*s)->s1, &(*s)->s2);
	vector_add(&(*v)->ops, fpb);
	display(*s, fpb);
}

/* 25 lines */
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

/* calc num rotates before a #pb, sorted in reverse order */
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

/* 17 lines */
void	get_b_sort(t_vec *v, t_node *s, t_elem *e)
{
	t_get_b_sort	vars;

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

/* 24 lines */
void	get_b_sort_hlpr(t_elem *e, t_get_b_sort vars)
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

void	init_issort_vars(t_is_sort_s *vars, t_vec *v, t_node *s)
{	
	vars->i = 0;
	vars->j = v->log_len - 1;
	vars->min = stack_min(s);
	vars->max = stack_max(s);
	vars->decr = 0;
	vars->incr = 0;
}

void	init_merge_vars(t_merge *vars, t_stacks *s)
{
	vars->s1_min = stack_min(s->s1);
	vars->s1_max = stack_max(s->s1);
	vars->s1_top = stack_peek(s->s1);
	vars->s1_top_next = stack_next_peek(s->s1);
	vars->s2_top = stack_peek(s->s2);	
}
