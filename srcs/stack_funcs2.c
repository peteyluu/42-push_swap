/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:30:50 by pluu              #+#    #+#             */
/*   Updated: 2017/06/05 15:03:21 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_dispose(t_node **s)
{
	while (*s)
	{
		free(*s);
		*s = (*s)->next;
	}
}

int	stack_len(t_node *s)
{
	int	len;

	len = 0;
	while (s)
	{
		len++;
		s = s->next;
	}
	return (len);
}

int	stack_peek(t_node *s)
{
	if (stack_empty(s))
		return (0);
	while (s->next)
		s = s->next;
	return (s->data);
}

int	stack_empty(t_node *s)
{
	return (s == NULL ? 1 : 0);
}

void	stack_print(t_node *s)
{
	while (s)
	{
		ft_printf("%d\n", s->data);
		s = s->next;
	}
}
