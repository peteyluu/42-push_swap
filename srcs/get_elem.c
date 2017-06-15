/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:25:56 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 14:42:11 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_elem2(t_vec *v, int target)
{
	int	i;

	i = 0;
	while (i < v->log_len)
	{
		if (v->arr[i].data > target)
			return (--i);
		i++;
	}
	return (-1);
}

int	get_elem1(t_vec *v, int target)
{
	int	i;

	i = 0;
	while (i < v->log_len)
	{
		if (v->arr[i].data > target)
			return (i);
		i++;
	}
	return (-1);
}

int	get_elem(t_vec *v, int target)
{
	int	i;

	i = 0;
	while (i < v->log_len)
	{
		if (v->arr[i].data == target)
			return (i);
		i++;
	}
	return (-1);
}
