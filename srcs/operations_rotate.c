/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:38:39 by pluu              #+#    #+#             */
/*   Updated: 2017/06/18 14:41:55 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **s1)
{
	t_node	*elem;

	if (stack_len(*s1) <= 1)
		return ;
	elem = stack_pop(s1);
	elem->next = *s1;
	*s1 = elem;
}

void	rb(t_node **s2)
{
	t_node	*elem;

	if (stack_len(*s2) <= 1)
		return ;
	elem = stack_pop(s2);
	elem->next = *s2;
	*s2 = elem;
}

void	rr(t_node **s1, t_node **s2)
{
	ra(s1);
	rb(s2);
}
