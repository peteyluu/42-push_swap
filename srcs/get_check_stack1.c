/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_check_stack1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 13:03:39 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 13:07:05 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_check_stack(int argc, char **argv, t_stacks **s)
{
	t_gcs	vars;

	vars.i = argc - 1;
	vars.j = 1;
	if (!argv[1])
		return (0);
	vars.k = 0;
	get_flag(s, &argv[1]);
	if (argc == 2 && !ft_isnumber(argv[1]))
	{
		argv = ft_strsplit(argv[1], ' ');
		vars.i = get_2darr_len(argv) - 1;
		vars.k = 0;
		vars.j = 0;
	}
	while (vars.i >= vars.j)
	{
		if (is_valid_num(argv, vars.i))
			stack_push(&(*s)->s1, ft_atoi(argv[vars.i--]));
		else
			return (0);
	}
	if (vars.k)
		arr_dispose(argv);	
	return (1);
}

void	get_flag(t_stacks **s, char **str)
{
	if (is_v_flag(str))
		(*s)->v_flag = 1;
	if (is_c_flag(str))
		(*s)->c_flag = 1;
}

int	is_v_flag(char **s)
{
	if (**s == '-' && *(*s + 1) == 'v')
	{
		*s += THREE;
		return (1);
	}
	return (0);
}

int	is_c_flag(char **s)
{
	if (**s == '-' && *(*s + 1) == 'c')
	{
		*s += THREE;
		return (1);
	}
	return (0);
}
