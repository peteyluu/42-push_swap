/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:45:46 by pluu              #+#    #+#             */
/*   Updated: 2017/06/12 16:36:24 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_sort(t_node *s1, t_node *s2)
{
	if (stack_empty(s1) || !stack_empty(s2))
		return (0);
	while (s1 && s1->next)
	{
		if (s1->data < s1->next->data)
			return (0);
		s1 = s1->next;
	}
	return (1);
}

int	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int(char *s)
{
	long	tmp;

	tmp = ft_strtol(s);
	return (tmp >= INT_MIN && tmp <= INT_MAX ? 1 : 0);
}

long	ft_strtol(char *s)
{
	int	isneg;
	long	res;

	res = 0;
	isneg = 1;
	if (*s == '-')
		isneg = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= 48 && *s <= 57)
	{
		res = res * 10 + (*s - 48);
		s++;
	}
	return (res * isneg);
}
