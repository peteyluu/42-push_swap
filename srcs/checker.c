/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:42:48 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 11:31:57 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*s;
	t_vector	*ops;

	init_stacks(&s);
	vector_new(&ops);
	if (argc == 1)
		return (0);
	else if (!get_check_stack(argc, argv, &s) || !get_check_ops(&ops))
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else
	{
		run(&s, ops);
		if (is_sort(s->s1, s->s2))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	vector_dispose(&ops);
	stacks_dispose(&s);
	return (0);
}

void	run(t_stacks **s, t_vector *ops)
{
	int	i;

	display(*s, fn);
	i = 0;
	while (i < ops->log_len)
	{
		run_op(s, ops->arr[i]);
		display(*s, ops->arr[i]);
		i++;
	}
}

void	run_op(t_stacks **s, int op)
{
	if (op == fsa)
		sa(&(*s)->s1);
	else if (op == fsb)
		sb(&(*s)->s2);
	else if (op == fss)
		ss(&(*s)->s1, &(*s)->s2);
	else if (op == fpa)
		pa(&(*s)->s1, &(*s)->s2);
	else if (op == fpb)
		pb(&(*s)->s1, &(*s)->s2);
	else if (op == fra)
		ra(&(*s)->s1);
	else if (op == frb)
		rb(&(*s)->s2);
	else if (op == frr)
		rr(&(*s)->s1, &(*s)->s2);
	else if (op == frra)
		rra(&(*s)->s1);
	else if (op == frrb)
		rrb(&(*s)->s2);
	else
		rrr(&(*s)->s1, &(*s)->s2);
}
