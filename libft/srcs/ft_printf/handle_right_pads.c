/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_right_pads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pluu <pluu@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:57:04 by pluu              #+#    #+#             */
/*   Updated: 2017/05/09 18:59:35 by pluu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_right_pads0(t_data **aoutput, char c, int *ai)
{
	(*ai)--;
	if (c == ' ')
	{
		ft_memset((*aoutput)->presult, c, *ai);
		*((*aoutput)->presult++ + *ai) = (*aoutput)->flag;
	}
	else
	{
		*(*aoutput)->presult++ = (*aoutput)->flag;
		ft_memset((*aoutput)->presult, c, *ai);
	}
}

static void	handle_right_pads1(t_data **aoutput, char c, int *ai)
{
	if (*ai)
	{
		if (c == ' ')
		{
			ft_memset((*aoutput)->presult, c, *ai);
			*((*aoutput)->presult + *ai) = '0';
			*((*aoutput)->presult + *ai + 1) = (*aoutput)->flag;
		}
		else
		{
			*((*aoutput)->presult) = '0';
			*((*aoutput)->presult + 1) = (*aoutput)->flag;
			ft_memset((*aoutput)->presult + 2, c, *ai);
		}
	}
	else
	{
		*((*aoutput)->presult) = '0';
		*((*aoutput)->presult + 1) = (*aoutput)->flag;
	}
	(*ai) += 2;
}

void	handle_right_pads(t_arg **ainfo, t_data **aoutput, char c, int *ai)
{
	(*aoutput)->flag = find_flag(ainfo, aoutput);
	if ((*aoutput)->flag)
	{
		if (*ai > 1 && (*aoutput)->flag != 'x' && (*aoutput)->flag != 'X')
			handle_right_pads0(aoutput, c, ai);
		else if ((*aoutput)->flag == 'x' || (*aoutput)->flag == 'X')
			handle_right_pads1(aoutput, c, ai);
		else
			*(*aoutput)->presult = (*aoutput)->flag;
	}
	else
	{
		if (*(*aoutput)->s_arg == '-' && c == '0' && ((*ainfo)->spec == 'd' || (*ainfo)->spec == 'i'))
			*(*aoutput)->presult++ = '-';
		ft_memset((*aoutput)->presult, c, *ai);
	}
}
