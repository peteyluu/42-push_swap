/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 14:11:29 by pluu              #+#    #+#             */
/*   Updated: 2017/06/15 14:11:31 by pluu             ###   ########.fr       */
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

void	vecs_dispose(t_vecs **v)
{
	vec_dispose(&(*v)->s1);
	vec_dispose(&(*v)->s2);
	vector_dispose(&(*v)->ops);
}

