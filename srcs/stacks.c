/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 14:08:57 by pluu              #+#    #+#             */
/*   Updated: 2017/06/05 14:49:49 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stacks **stacks)
{
	*stacks = (t_stacks*)malloc(sizeof(t_stacks));
	(*stacks)->s1 = NULL;
	(*stacks)->s2 = NULL;
}

void	stacks_dispose(t_stacks **stacks)
{
	stack_dispose(&(*stacks)->s1);
	stack_dispose(&(*stacks)->s2);
	free(*stacks);
}
