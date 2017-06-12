/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_check_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 18:02:17 by pluu              #+#    #+#             */
/*   Updated: 2017/06/12 16:33:22 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_check_ops(t_vector **ops)
{
	char	*line;
	int	i;
	int	op;

	i = 0;
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (ft_strcmp(line, "") == 0)
			break ;
		else
		{
			if (!(op = get_op(line)))
				return (0);
			free(line);
			vector_add(ops, op);
		}
	}
	return (1);
}

int	get_op(char *s)
{
	if (!ft_strcmp(s, "sa"))
		return (fsa);
	else if (!ft_strcmp(s, "sb"))
		return (fsb);
	else if (!ft_strcmp(s, "ss"))
		return (fss);
	else if (!ft_strcmp(s, "pa"))
		return (fpa);
	else if (!ft_strcmp(s, "pb"))
		return (fpb);
	else if (!ft_strcmp(s, "ra"))
		return (fra);
	else if (!ft_strcmp(s, "rb"))
		return (frb);
	else if (!ft_strcmp(s, "rr"))
		return (frr);
	else if (!ft_strcmp(s, "rra"))
		return (frra);
	else if (!ft_strcmp(s, "rrb"))
		return (frrb);
	else if (!ft_strcmp(s, "rrr"))
		return (frrr);
	return (fn);
}
