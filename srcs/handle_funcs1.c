/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_funcs1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:23:48 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 15:02:39 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_top_min1(t_stacks **s, t_vecs **v, int data)
{
	t_top	vars;

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
