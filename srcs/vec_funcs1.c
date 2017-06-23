/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_funcs1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:07:11 by pluu              #+#    #+#             */
/*   Updated: 2017/06/23 13:04:57 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_vec(t_vec **v, int len)
{
	if (!(*v = (t_vec*)malloc(sizeof(t_vec))))
		exit(-1);
	(*v)->log_len = 0;
	(*v)->alloc_len = len;
	if (!((*v)->arr = (t_elem*)malloc(sizeof(t_elem) * len)))
		exit(-1);
}

void	vec_dispose(t_vec **v)
{
	if (!*v)
		return ;
	free((*v)->arr);
	free(*v);
}

void	vec_print(t_vec *v)
{
	int	i;

	i = 0;
	while (i < v->log_len)
	{
		ft_printf("%d_%d_%d_%d_%d_%d_%d_%d_%d\n",
				v->arr[i].data,
				v->arr[i].pos,
				v->arr[i].a_op_cnt,
				v->arr[i].a_op,
				v->arr[i].b_op_cnt,
				v->arr[i].b_op,
				v->arr[i].ab_op_cnt,
				v->arr[i].ab_op,
				v->arr[i].total);
		i++;
	}
}

void	pop_vec_stacks(t_vecs **v, t_stacks *s)
{
	init_vec(&(*v)->s1, stack_len(s->s1));
	init_vec(&(*v)->s2, stack_len(s->s2));
	pop_vec(&(*v)->s1, s->s1);
	pop_vec(&(*v)->s2, s->s2);
}


void	pop_vec(t_vec **v, t_node *s1)
{
	int	len;

	len = (*v)->alloc_len - 1;
	while (s1)
	{
		(*v)->arr[(*v)->log_len].data = s1->data;
		(*v)->arr[(*v)->log_len].pos = len - (*v)->log_len;
		(*v)->log_len++;
		s1 = s1->next;
	}
}
