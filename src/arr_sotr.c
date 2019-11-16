/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sotr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:57:55 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/30 17:45:52 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

long int	swap_i(long int *l, long int *b)
{
	long int t;

	t = *l;
	*l = *b;
	*b = t;
	return (1);
}

int			print_com(int cm)
{
	if (cm == 's')
		write(1, "sa\n", 3);
	else if (cm == SA)
		write(1, "sa\n", 3);
	else if (cm == SB)
		write(1, "sb\n", 3);
	else if (cm == SS)
		write(1, "ss\n", 3);
	else if (cm == PB)
		write(1, "pb\n", 3);
	else if (cm == PA)
		write(1, "pa\n", 3);
	else if (cm == RA)
		write(1, "ra\n", 3);
	else if (cm == RB)
		write(1, "rb\n", 3);
	else if (cm == RR)
		write(1, "rr\n", 3);
	else if (cm == RRA)
		write(1, "rra\n", 4);
	else if (cm == RRB)
		write(1, "rrb\n", 4);
	else if (cm == RRR)
		write(1, "rrr\n", 4);
	return (0);
}

/*
** check stack_B leava acom// every element to get tot top
** check every element how muchi tales to get up;
**  every el's index --> amunt of rotations
** *1 create first node and each time check len of list to cmpr w minimum
** also save the n in node's
** **2
** while (--i - 1 > 0)//(++cnt < i - 1)//!?
*/

long		up_stack(t_arr *fi, t_op *ins, long i)
{
	long	cnt;

	cnt = -1;
	if (i <= fi->bsz / 2)
	{
		ins->bsp = i;
		ins->bdr = RB;
	}
	else
	{
		ins->bsp = fi->bsz - i;
		ins->bdr = RRB;
	}
	return (ins->bsp);
}

/*
** //find place & count operaa
** //stack A //least/biggest in plain -> just PA 0op
** //detedting if stack A is tround or plain
** 	//ink = ink < 0 ? mini : ink;//for circlesd
** 	//lest of all in circle?
** 	//if predposl?
*/

long		get_toplace(t_arr *fi, long i, t_op *ins)
{
	long ink;

	ink = round_or_plain(fi, i);
	if (ink <= fi->asz / 2)
	{
		ins->asp = ink;
		ins->adr = RA;
	}
	else
	{
		ins->adr = RRA;
		ins->asp = ink == fi->asz ? 0 : fi->asz - ink;
	}
	return (ins->asp);
}
