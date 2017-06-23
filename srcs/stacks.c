/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 14:08:57 by pluu              #+#    #+#             */
/*   Updated: 2017/06/23 12:57:55 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stacks **s)
{
	if (!(*s = (t_stacks*)malloc(sizeof(t_stacks))))
		exit(-1);
	(*s)->s1 = NULL;
	(*s)->s2 = NULL;
	(*s)->v_flag = 0;
	(*s)->c_flag = 0;
}

void	stacks_dispose(t_stacks **s)
{
	stack_dispose(&(*s)->s1);
	stack_dispose(&(*s)->s2);
	free(*s);
}
