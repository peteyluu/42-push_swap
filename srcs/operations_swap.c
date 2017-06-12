/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:37:26 by pluu              #+#    #+#             */
/*   Updated: 2017/05/17 18:37:41 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **s1)
{
	t_node	*curr;
	t_node	*prev;

	if (stack_len(*s1) <= 1)
		return ;
	curr = *s1;
	while (curr)
	{
		if (!curr->next)
			break ;
		prev = curr;
		curr = curr->next;
	}
	swap(&prev->data, &curr->data);
}

void	sb(t_node **s2)
{
	t_node	*curr;
	t_node	*prev;

	if (stack_len(*s2) <= 1)
		return ;
	curr = *s2;
	while (curr)
	{
		if (!curr->next)
			break ;
		prev = curr;
		curr = curr->next;
	}
	swap(&prev->data, &curr->data);
}

void	ss(t_node **s1, t_node **s2)
{
	sa(s1);
	sb(s2);
}
