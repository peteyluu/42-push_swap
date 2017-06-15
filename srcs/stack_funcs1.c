/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:30:41 by pluu              #+#    #+#             */
/*   Updated: 2017/06/14 14:41:35 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_new(int elem)
{
	t_node	*new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		exit(-1);
	new->data = elem;
	new->next = NULL;
	return (new);
}

void	stack_push(t_node **s, int elem)
{
	t_node	*curr;

	if (!*s)
		*s = stack_new(elem);
	else
	{
		curr = *s;
		while (curr->next)
		{
			if (!curr->next)
				break ;
			curr = curr->next;
		}
		curr->next = stack_new(elem);
	}
}

void	stack_push_node(t_node **s, t_node *node)
{	
	t_node	*curr;

	if (!*s)
		*s = node;
	else
	{
		curr = *s;
		while (curr->next)
		{
			if (!curr->next)
				break ;
			curr = curr->next;
		}
		curr->next = node;
	}
}

t_node	*stack_pop(t_node **s)
{
	t_node	*curr;
	t_node	*prev;

	if (!*s)
		return (NULL);
	if (!(*s)->next)
	{
		curr = *s;
		*s = NULL;
		return (curr);
	}
	curr = *s;
	while (curr)
	{
		if (!curr->next)
			break ;
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	return (curr);
}

t_node	*stack_shift(t_node **s)
{
	t_node *elem;

	elem = *s;
	*s = (*s)->next;
	elem->next = NULL;
	return (elem);
}
