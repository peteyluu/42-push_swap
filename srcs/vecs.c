/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 14:11:29 by pluu              #+#    #+#             */
/*   Updated: 2017/06/12 16:10:44 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_vecs(t_vecs **vecs)
{
	*vecs = (t_vecs*)malloc(sizeof(t_vecs));
	(*vecs)->s1 = NULL;
	(*vecs)->s2 = NULL;
	(*vecs)->ops = NULL;
}

void	init_vec(t_vec **v, int len)
{
	*v = (t_vec*)malloc(sizeof(t_vec));
	(*v)->log_len = 0;
	(*v)->alloc_len = len;
	if (!((*v)->arr = (t_elem*)malloc(sizeof(t_elem) * len)))
		exit(-1);
}

void	pop_vec_stacks(t_vecs **v, t_stacks *s)
{
	init_vec(&(*v)->s1, stack_len(s->s1));
	init_vec(&(*v)->s2, stack_len(s->s2));
	pop_vec(&(*v)->s1, s->s1);
	pop_vec(&(*v)->s2, s->s2);
}

void	pop_vec_total(t_vec **v)
{
	int	i;

	i = 0;
	while (i < (*v)->log_len)
	{
		(*v)->arr[i].total = (*v)->arr[i].a_op_cnt + (*v)->arr[i].b_op_cnt + (*v)->arr[i].ab_op_cnt;
		i++;
	}
}


void	pop_vec_a_top(t_vec **v, t_node *s)
{
	int	i;

	i = 0;
	while (i < (*v)->log_len)
	{
		get_vec_a_top(&(*v)->arr[i], s);
		i++;
	}
}

void	get_vec_a_top(t_elem *e, t_node *s)
{
	int	top;
	int	bot;

	top = e->pos;
	bot = ft_abs(e->pos - stack_len(s));
	if (!top)
	{
		e->a_op_cnt = top;
		e->a_op = fn;
	}
	else if (top < bot)
	{
		e->a_op_cnt = top;
		e->a_op = fra;
	}
	else
	{
		e->a_op_cnt = bot;
		e->a_op = frra;
	}
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

void	vec_dispose(t_vec **v)
{
	if (!*v)
		return ;
	free((*v)->arr);
	free(*v);
}

void	vecs_dispose(t_vecs **v)
{
	vec_dispose(&(*v)->s1);
	vec_dispose(&(*v)->s2);
	vector_dispose(&(*v)->ops);
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

void	upd_pos_ra(t_vec **v, int j)
{
	int	i;

	i = 0;
	while (i < (*v)->log_len)
	{
		if ((*v)->arr[i].pos == 0)
			(*v)->arr[i].pos = j;
		else
			(*v)->arr[i].pos--;
		i++;
	}
}

void	upd_pos_rra(t_vec **v, int j)
{
	int	i;

	i = 0;
	while (i < (*v)->log_len)
	{
		if ((*v)->arr[i].pos == j)
			(*v)->arr[i].pos = 0;
		else
			(*v)->arr[i].pos++;
		i++;
	}
}

void	upd_pos_sa(t_vec **v)
{
	int	tmp;

	tmp = (*v)->arr[0].pos;
	(*v)->arr[0].pos = (*v)->arr[1].pos;
	(*v)->arr[1].pos = tmp; 	
}
