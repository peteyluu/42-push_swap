/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:02:47 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 15:02:58 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_top_max(t_stacks **s, t_vecs **v, int data)
{
	t_top 	vars;

	vars.len = stack_len((*s)->s2) - 1;
	vars.tmp = (*v)->s2->arr[get_elem((*v)->s2, data)];
	vars.top = 0;
	if (vars.tmp.pos)
		vars.top = vars.tmp.pos;
	vars.bot = ft_abs(vars.tmp.pos - ((*v)->s2->log_len - 1)) + 1;
	handle_top_max_hlpr(s, v, vars);
}

void	handle_top_max_hlpr(t_stacks **s, t_vecs **v, t_top vars)
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
	t_top	vars;

	vars.len = stack_len((*s)->s1) - 1;
	vars.tmp = (*v)->s1->arr[get_elem((*v)->s1, data)];
	vars.top = 0;
	if (vars.tmp.pos)
		vars.top = vars.tmp.pos;
	vars.bot = ft_abs(vars.tmp.pos - ((*v)->s1->log_len - 1)) + 1;
	handle_top_min_hlpr(s, v, vars);
	sort_pos(&(*v)->s1);
}

void	handle_top_min_hlpr(t_stacks **s, t_vecs **v, t_top vars)
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

