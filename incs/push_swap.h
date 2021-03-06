/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 18:41:30 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 15:06:47 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "ft_printf.h"
# define THREE 3
# define FOUR 4
# define FIVE 5
# define SPACING 13

enum
{
	fn,
	fsa,
	fsb,
	fss,
	fpa,
	fpb,
	fra,
	frb,
	frr,
	frra,
	frrb,
	frrr
};

typedef struct		s_gcs
{
	int		i;
	int		j;
	int		k;
}			t_gcs;

typedef struct		s_elem
{
	int		data;
	int		pos;
	int		a_op_cnt;
	int		a_op;
	int		b_op_cnt;
	int		b_op;
	int		ab_op_cnt;
	int		ab_op;
	int		total;
}			t_elem;

typedef struct		s_iamm
{
	int		min;
	int		max;
	int		idx_min;
	int		idx_max;
	int		j;
}			t_iamm;

typedef struct		s_gbs
{
	int		min;
	int		max;
	int		len;
	int		top;
	int		bot;
	int		tmp1;
	int		tmp2;
	t_elem		tmp;
}			t_gbs;

typedef struct		s_top
{
	int		top;
	int		bot;
	int		len;
	t_elem		tmp;
}			t_top;

typedef struct		s_sort
{
	int		i;
	int		j;
	int		min;
	int		max;
	int		decr;
	int		incr;

}			t_sort;

typedef struct		s_merge
{
	int		s1_min;
	int		s1_max;
	int		s1_top;
	int		s1_top_next;
	int		s2_top;
}			t_merge;

typedef struct		s_node
{
	int		data;
	struct s_node	*next;
}			t_node;

typedef struct		s_stacks
{
	t_node		*s1;
	t_node		*s2;
	int		v_flag;
	int		c_flag;
}			t_stacks;

typedef struct		s_vector
{
	int		*arr;
	int		log_len;
	int		alloc_len;	
}			t_vector;

typedef struct		s_vec
{
	t_elem		*arr;
	int		log_len;
	int		alloc_len;
}			t_vec;

typedef struct		s_vecs
{
	t_vec		*s1;
	t_vec		*s2;
	t_vector	*ops;
}			t_vecs;

/* display.c */
void    display(t_stacks *s, int func);
void    disp_dispose_node(t_node **s1, t_node **s2);
int     num_digits(int n);

/* display_v.c */
void    disp_header(void);
void    disp_stacks(t_stacks *s);
void    disp_spacing(int n);
void    disp_op(int op);

/*display_c.c */
void    disp_header_c(void);
void    disp_stacks_c(t_stacks *s);
void    disp_spacing_c(int n);
void    disp_op_c(int op);

/* push_swap.c */
void    solve_ps(t_stacks **s, t_vecs **v);
void    sort_three(t_stacks **s, t_vector **v);
void    sort_five(t_stacks **s, t_vecs **v);
void    sort_rand(t_stacks **s, t_vecs **v);

/* sort_funcs1.c */
int	is_sort(t_node *s1, t_node *s2);
int	is_sort_sa(t_node *s1);
void    init_issort_vars(t_sort *vars, t_vec *v, t_node *s);
int     is_sort_stack(t_vec *v, t_node *s);
void    sort_ascend(t_stacks **s, t_vecs **v);

/* sort_funcs2.c */
void	sort_pos(t_vec **v);
void    sort_data(t_vec **v);
void	sort_total(t_vec**v);

/* ps_funcs.c */
void    exe_elem(t_elem e, t_stacks **s, t_vector **ops);
void    exe_op(t_stacks **s, int op);
void    ops_print(t_vector *ops);

/* merge.c */
void    init_merge_vars(t_merge *vars, t_stacks *s);
void    merge(t_stacks **s, t_vecs **v);
void    merge_hlpr1(t_stacks **s, t_vecs **v, int s2_top);
int     is_adj_max_min(t_node *s, t_vec *v);
void    handle_adj_max_min(t_stacks **s, t_vecs **v, int data);

/* handle_funcs1.c */
void    handle_top_min1(t_stacks **s, t_vecs **v, int data);
void    handle_data_top(t_stacks **s, t_vecs **v, t_elem e);
void    handle_beg_sa(t_stacks **s, t_vecs **v);
void    handle_beg_pb(t_stacks **s, t_vecs **v);

/* handle_funcs2.c */
void    handle_top_max(t_stacks **s, t_vecs **v, int data);
void    handle_top_max_hlpr(t_stacks **s, t_vecs **v, t_top vars);
void    handle_top_min(t_stacks **s, t_vecs **v, int data);
void    handle_top_min_hlpr(t_stacks **s, t_vecs **v, t_top vars);

/* get_check_stack1.c */
int	get_check_stack(int argc, char **argv, t_stacks **s);
void    get_flag(t_stacks **s, char **str);
int     is_v_flag(char **s);
int     is_c_flag(char **s);

/* get_check_stack2.c */
int	is_dup(char **argv, int j);
int	get_2darr_len(char **argv);
void	arr_dispose(char **arr);
int	is_valid_num(char **argv, int i);

/* get_check_ops.c */
int	get_check_ops(t_vector **ops);
int	get_op(char *s);

/* get_elem.c */
int	get_elem(t_vec *v, int target);
int     get_elem1(t_vec *v, int target);
int     get_elem2(t_vec *v, int target);

/* checker.c */
void	run(t_stacks **s, t_vector *ops);
void	run_op(t_stacks **s, int op);

/* vecs.c */
void    init_vecs(t_vecs **vecs);
void    vecs_dispose(t_vecs **v);

/* vec_funcs1.c */
void    init_vec(t_vec **v, int len);
void    vec_dispose(t_vec **v);
void    vec_print(t_vec *v);
void    pop_vec_stacks(t_vecs **v, t_stacks *s);
void    pop_vec(t_vec **v, t_node *s1);

/* vec_funcs2.c */
void    pop_vec_a_top(t_vec **v, t_node *s);
void    get_vec_a_top(t_elem *e, t_node *s);
void    pop_vec_b_sort(t_vecs **v, t_node *s);
void	get_b_sort(t_vec *v, t_node *s, t_elem *e);
void    get_b_sort_hlpr(t_elem *e, t_gbs vars);

/* vec_funcs3.c */
void    pop_vec_ab_op(t_vec **v);
void    pop_vec_ab_op_hlpr(t_elem *e);
void    pop_vec_total(t_vec **v);

/* update_pos.c */
void    upd_pos_rra(t_vec **v, int j);
void    upd_pos_ra(t_vec **v, int j);
void    upd_pos_sa(t_vec **v);

/* stacks.c */
void    init_stacks(t_stacks **s);
void    stacks_dispose(t_stacks **s);

/* stack */
t_node	*stack_new(int elem);
void	stack_push(t_node **s, int elem);
void	stack_push_node(t_node **s, t_node *node);
t_node	*stack_pop(t_node **s);
int	stack_pop_data(t_node *s);
t_node	*stack_shift(t_node **s);
void	stack_dispose(t_node **s);
void	stack_print(t_node *s);
int	stack_len(t_node *s);
int	stack_empty(t_node *s);
int	stack_peek(t_node *s);
int	stack_next_peek(t_node *s);
void	stack_dup(t_node *s, t_node **dup_s);
int     stack_max(t_node *s);
int     stack_min(t_node *s);

/* vector.c */
void	vector_new(t_vector **ops);
void	vector_add(t_vector **ops, int elem);
void	vector_grow(t_vector **ops);
void	vector_dispose(t_vector **ops);
void	vector_print(t_vector *ops);

/* operations */
void	sa(t_node **s1);
void	sb(t_node **s2);
void	ss(t_node **s1, t_node **s2);
void	pa(t_node **s1, t_node **s2);
void	pb(t_node **s1, t_node **s2);
void	ra(t_node **s1);
void	rb(t_node **s2);
void	rr(t_node **s1, t_node **s2);
void	rra(t_node **s1);
void	rrb(t_node **s2);
void	rrr(t_node **s1, t_node **s2);

/* helper_funcs.c */
int	ft_abs(int n);
void	swap(int *a, int *b);
int	ft_isnumber(char *s);
int	is_int(char *s);
long	ft_strtol(char *s);

#endif
