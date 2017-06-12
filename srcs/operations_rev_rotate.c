/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:39:12 by pluu              #+#    #+#             */
/*   Updated: 2017/05/17 18:39:26 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **s1)
{
	stack_push_node(s1, stack_shift(s1));
}

void	rrb(t_node **s2)
{
	stack_push_node(s2, stack_shift(s2));
}

void	rrr(t_node **s1, t_node **s2)
{
	rra(s1);
	rrb(s2);
}
