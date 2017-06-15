/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 12:59:55 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 13:00:19 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	disp_header(void)
{
	ft_putstr("   Stack A   |   Stack B   \n");
	ft_putstr("---------------------------\n");
}

void	disp_stacks(t_stacks *s)
{
	t_stacks	*dup_s;
	t_node		*s1_pop;
	t_node		*s2_pop;


	init_stacks(&dup_s);
	stack_dup(s->s1, &dup_s->s1);
	stack_dup(s->s2, &dup_s->s2);
	disp_header();
	while (!stack_empty(dup_s->s1) || !stack_empty(dup_s->s2))
	{
		s1_pop = stack_pop(&dup_s->s1);
		s2_pop = stack_pop(&dup_s->s2);
		if (s1_pop)
		{
			ft_printf("%d", s1_pop->data);
			disp_spacing(num_digits(s1_pop->data));
		}
		else
			ft_putstr("             | ");
		if (s2_pop)
			ft_printf("%d", s2_pop->data);
		ft_putchar('\n');
		disp_dispose_node(&s1_pop, &s2_pop);
	}
	stacks_dispose(&dup_s);
}

void	disp_spacing(int n)
{
	n = SPACING - n;
	while (n--)
		ft_putchar(' ');
	ft_putstr("| ");
}

void	disp_op(int op)
{
	if (op == fsa)
		ft_putstr("sa\n");
	else if (op == fsb)
		ft_putstr("sb\n");
	else if (op == fpa)
		ft_putstr("pa\n");
	else if (op == fpb)
		ft_putstr("pb\n");
	else if (op == fra)
		ft_putstr("ra\n");
	else if (op == frb)
		ft_putstr("rb\n");
	else if (op == frr)
		ft_putstr("rr\n");
	else if (op == frra)
		ft_putstr("rra\n");
	else if (op == frrb)
		ft_putstr("rrb\n");
	else if (op == frrr)
		ft_putstr("rrr\n");
	else
		ft_putstr("none\n");
}
