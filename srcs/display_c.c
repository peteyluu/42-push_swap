/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 12:58:45 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 12:58:59 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	disp_header_c(void)
{
	ft_putstr("\033[22;31m   Stack A  \033[0m \033[22;32m|\033[0m \033[22;34m  Stack B   \033[0m\n");
	ft_putstr("\033[22;32m---------------------------\033[0m\n");
}

void	disp_stacks_c(t_stacks *s)
{
	t_stacks	*dup_s;
	t_node		*s1_pop;
	t_node		*s2_pop;


	init_stacks(&dup_s);
	stack_dup(s->s1, &dup_s->s1);
	stack_dup(s->s2, &dup_s->s2);
	disp_header_c();
	while (!stack_empty(dup_s->s1) || !stack_empty(dup_s->s2))
	{
		s1_pop = stack_pop(&dup_s->s1);
		s2_pop = stack_pop(&dup_s->s2);
		if (s1_pop)
		{
			ft_printf("\033[22;31m%d\033[0m", s1_pop->data);
			disp_spacing_c(num_digits(s1_pop->data));
		}
		else
			ft_putstr("             \033[22;32m|\033[0m ");
		if (s2_pop)
			ft_printf("\033[22;34m%d\033[0m", s2_pop->data);
		ft_putchar('\n');
		disp_dispose_node(&s1_pop, &s2_pop);
	}
	stacks_dispose(&dup_s);
}

void	disp_op_c(int op)
{
	if (op == fsa)
		ft_putstr("\033[22;32msa\033[0m\n");
	else if (op == fsb)
		ft_putstr("\033[22;32msb\033[0m\n");
	else if (op == fpa)
		ft_putstr("\033[22;32mpa\033[0m\n");
	else if (op == fpb)
		ft_putstr("\033[22;32mpb\033[0m\n");
	else if (op == fra)
		ft_putstr("\033[22;32mra\033[0m\n");
	else if (op == frb)
		ft_putstr("\033[22;32mrb\033[0m\n");
	else if (op == frr)
		ft_putstr("\033[22;32mrr\033[0m\n");
	else if (op == frra)
		ft_putstr("\033[22;32mrra\033[0m\n");
	else if (op == frrb)
		ft_putstr("\033[22;32mrrb\033[0m\n");
	else if (op == frrr)
		ft_putstr("\033[22;32mrrr\033[0m\n");
	else
		ft_putstr("\033[22;32mnone\033[0m\n");
}

void	disp_spacing_c(int n)
{
	n = SPACING - n;
	while (n--)
		ft_putchar(' ');
	ft_putstr("\033[22;32m|\033[0m ");
}
