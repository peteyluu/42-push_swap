/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 13:50:36 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 13:00:25 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_stacks *s, int func)
{
	if (s->c_flag)
	{
		disp_stacks_c(s);
		disp_op_c(func);
		ft_putchar('\n');
	}
	else if (s->v_flag)
	{
		disp_stacks(s);
		disp_op(func);
		ft_putchar('\n');
	}
}

void	disp_dispose_node(t_node **s1, t_node **s2)
{
	ft_memdel((void**)s1);
	ft_memdel((void**)s2);
}

int	num_digits(int n)
{
	int	cnt;

	if (!n)
		return (1);
	cnt = 0;
	if (n < 0)
		cnt = 1;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}
