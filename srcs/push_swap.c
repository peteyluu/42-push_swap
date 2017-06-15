/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:43:05 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 14:41:32 by pluu             ###   ########.fr       */
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
	t_top	vars;

	vars.top = stack_peek((*s)->s1);
	vars.bot = (*s)->s1->data;
	while (!is_sort_sa((*s)->s1))
	{
		while (vars.top < vars.bot && !is_sort_sa((*s)->s1))
		{
			rra(&(*s)->s1);
			vector_add(v, frra);
			display(*s, frra);
			sa(&(*s)->s1);
			display(*s, fsa);
			vector_add(v, fsa);
			vars.top = stack_peek((*s)->s1);
			vars.bot = (*s)->s1->data;
		}
		while (vars.top > vars.bot)
		{
			rra(&(*s)->s1);
			vector_add(v, frra);
			display(*s, frra);
			vars.top = stack_peek((*s)->s1);
			vars.bot = (*s)->s1->data;
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
