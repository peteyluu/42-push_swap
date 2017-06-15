/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_check_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:00:36 by pluu              #+#    #+#             */
/*   Updated: 2017/06/14 15:30:41 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 29 lines */
int	get_check_stack(int argc, char **argv, t_stacks **s)
{
	int	i;
	int	j;
	int	strsplit_flag;

	i = argc - 1;
	j = 1;
	if (!argv[1])
		return (0);
	strsplit_flag = 0;
	if (is_v_flag(&argv[1]))
		(*s)->v_flag = 1;
	if (is_c_flag(&argv[1]))
		(*s)->c_flag = 1;
	if (argc == 2 && !ft_isnumber(argv[1]))
	{
		argv = ft_strsplit(argv[1], ' ');
		i = get_2darr_len(argv) - 1;
		strsplit_flag = 1;
		j = 0;
	}
	while (i >= j)
	{
		if (is_valid_num(argv, i))
			stack_push(&(*s)->s1, ft_atoi(argv[i--]));
		else
			return (0);
	}
	if (strsplit_flag)
		arr_dispose(argv);	
	return (1);
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

int	is_valid_num(char **argv, int i)
{
	if (!ft_isnumber(argv[i]))
		return (0);
	if (!is_int(argv[i]))
		return (0);
	if (is_dup(argv, i))
		return (0);
	return (1);
}

void	arr_dispose(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	get_2darr_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}


int	is_dup(char **argv, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (ft_strcmp(argv[i], argv[j]) == 0)
			return (1);
		i++;
	}
	return (0);
}
