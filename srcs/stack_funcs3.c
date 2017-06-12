/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:33:50 by pluu              #+#    #+#             */
/*   Updated: 2017/06/05 15:09:57 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_next_peek(t_node *s)
{
	if (stack_empty(s))
		return (0);
	while (s->next->next)
		s = s->next;
	return (s->data);
}

void	stack_dup(t_node *s, t_node **dup_s)
{
	*dup_s = NULL;
	while (s)
	{
		stack_push(dup_s, s->data);
		s = s->next;	
	}
}

int	stack_max(t_node *s)
{
	int	max;

	max = s->data;
	s = s->next;
	while (s)
	{
		if (s->data > max)
			max = s->data;
		s = s->next;
	}
	return (max);
}

int	stack_min(t_node *s)
{
	int	min;

	min = s->data;
	s = s->next;
	while (s)
	{
		if (s->data < min)
			min = s->data;
		s = s->next;
	}
	return (min);
}
