/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 18:38:04 by pluu              #+#    #+#             */
/*   Updated: 2017/05/17 18:38:16 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **s1, t_node **s2)
{
	if (stack_len(*s2) <= 0)
		return ;
	stack_push_node(s1, stack_pop(s2));
}

void	pb(t_node **s1, t_node **s2)
{
	if (stack_len(*s1) <= 0)
		return ;
	stack_push_node(s2, stack_pop(s1));
}
