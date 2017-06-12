/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:42:48 by pluu              #+#    #+#             */
/*   Updated: 2017/06/12 16:42:51 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_vector	*ops;

	init_stacks(&stacks);
	vector_new(&ops);
	if (argc == 1)
		return (0);
	else if (!get_check_stack(argc, argv, &stacks->s1) || !get_check_ops(&ops))
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else
	{
		run(&stacks->s1, &stacks->s2, ops);
		if (is_sort(stacks->s1, stacks->s2))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	vector_dispose(&ops);
	stacks_dispose(&stacks);
	return (0);
}


void	run_op(t_node **s1, t_node **s2, int op)
{

	if (op == fsa)
		sa(s1);
	else if (op == fsb)
		sb(s2);
	else if (op == fss)
		ss(s1, s2);
	else if (op == fpa)
		pa(s1, s2);
	else if (op == fpb)
		pb(s1, s2);
	else if (op == fra)
		ra(s1);
	else if (op == frb)
		rb(s2);
	else if (op == frr)
		rr(s1, s2);
	else if (op == frra)
		rra(s1);
	else if (op == frrb)
		rrb(s2);
	else
		rrr(s1, s2);
}

void	run(t_node **s1, t_node **s2, t_vector *ops)
{
	int	i;
	int	j;

	i = 0;
	j = ops->log_len;
	while (i < j)
	{
		run_op(s1, s2, ops->arr[i]);
		i++;
	}
}
