/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_check_stack2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 13:06:40 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 13:06:50 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
