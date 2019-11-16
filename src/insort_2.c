/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insort_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:10:50 by ddratini          #+#    #+#             */
/*   Updated: 2019/11/16 19:12:28 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

/*
** 5 0
** 1 45
** 2
** 3
** //lokinf atually for a place
** //if b[i] > all in A just Push? 0 moves//if k == fi->asz?
** //(mini > maxi)//(maxi > mini)
** //if (fi->bst[i] > fi->ast[k])
** //for round s
** //till round circel circle
** third while//if round-> max in mid
** 		//if its biggest -> its placi is in mid m->maxin *****
*/

/*
**  //, long maxi, long mini)
*/

/*
**	//way home - lol
** //exah each time save comline s//then free
** ///collecting the path-ways and saving the minimum
**;//saving minimalss
**get top place returns theminimal movemnts in A for B-el
** //up_st ret min-move for B to-ptop
** * //init co here///last- PA
** //filling the node with operations till up_Bstack
*/

t_op		compute_path(t_arr *fi, t_op ins)
{
	long	i;
	long	min;
	t_op	mins;
	long	aop;
	long	bop;

	i = -1;
	min = LOL - 1;
	while (++i < fi->bsz)
	{
		if (i == 0)
			mins = ins;
		aop = get_toplace(fi, i, &ins);
		bop = up_stack(fi, &ins, i);
		if ((ins.total = aop + bop + 1) < min)
		{
			mins = ins;
			min = aop + bop + 1;
		}
	}
	return (mins);
}

int			isoptim(t_op ins, t_arr *fi)
{
	if (ins.rram > 0)
	{
		while (ins.rram > 0)
		{
			rot_a(&fi->bst, fi->bsz, 0);
			rot_a(&fi->ast, fi->asz, 0);
			print_com(RR);
			--ins.rram;
		}
		return (1);
	}
	if (ins.rrram > 0)
	{
		while (ins.rrram > 0)
		{
			revrot(&fi->ast, fi->asz);
			revrot(&fi->bst, fi->bsz);
			print_com(RRR);
			--ins.rrram;
		}
		return (2);
	}
	return (0);
}

void		execute(t_arr *fi, t_op ins, long i)
{
	i = -1;
	isoptim(ins, fi);
	if (ins.adr == RA)
		while (++i < ins.asp)
			rot_a(&fi->ast, fi->asz, 1);
	i = -1;
	if (ins.adr == RRA)
		while (++i < ins.asp)
		{
			revrot(&fi->ast, fi->asz);
			print_com(RRA);
		}
	i = -1;
	if (ins.bdr == RB)
		while (++i < ins.bsp)
			rot_a(&fi->bst, fi->bsz, 2);
	i = -1;
	if (ins.bdr == RRB)
		while (++i < ins.bsp)
		{
			revrot(&fi->bst, fi->bsz);
			print_com(RRB);
		}
	push_b_r(&fi->bst, &fi->ast, &fi->bsz, &fi->asz);
	print_com(PA);
}

/*
** //exec(com, fi);//insertung//rotcir
*/

t_op		optimise(t_op ins)
{
	long i;
	long j;

	j = ins.bsp;
	i = ins.asp;
	if (ins.asp <= 0 || ins.bsp <= 0)
		return (ins);
	if ((ins.adr == RA && ins.bdr == RB) || (ins.adr == RRA && ins.bdr == RRA))
	{
		while (i > 0 && j > 0)
		{
			--i;
			--j;
			if (ins.adr == RA)
				++ins.rram;
			else if (ins.adr == RRA)
				++ins.rrram;
			--ins.bsp;
			--ins.asp;
		}
		return (ins);
	}
	return (ins);
}

void		insort_(t_arr *fi)
{
	t_op	path;
	t_op	ins;

	ins = top_fil();
	while (fi->bsz)
	{
		path = compute_path(fi, ins);
		path = optimise(path);
		execute(fi, path, -1);
	}
	rstack(fi, EMP);
}
