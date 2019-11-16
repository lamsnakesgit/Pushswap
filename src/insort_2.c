/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insort_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:10:50 by ddratini          #+#    #+#             */
/*   Updated: 2019/11/16 17:10:52 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

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
		ins->bdir = RB;
	}
	else
	{
		ins->bsp = fi->bsz - i;
		ins->bdir = RRB;
	}
	return (ins->bsp);
}

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
** 		//if its biggest -> its placi is in mid m->maxin
**
**
*/

/*
**  //, long maxi, long mini)
*/

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
		ins->adir = RA;
	}
	else
	{
		ins->adir = RRA;
		ins->asp = ink == fi->asz ? 0 : fi->asz - ink;
	}
	return (ins->asp);
}

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

void		execute(t_arr *fi, t_op ins, long i)
{
	i = -1;
	if (ins.adir == RA)
		while (++i < ins.asp)
			rot_a(&fi->ast, fi->asz, 1);
	i = -1;
	if (ins.adir == RRA)
		while (++i < ins.asp)
		{
			revrot(&fi->ast, fi->asz);
			print_com(RRA);
		}
	i = -1;
	if (ins.bdir == RB)
		while (++i < ins.bsp)
			rot_a(&fi->bst, fi->bsz, 2);
	i = -1;
	if (ins.bdir == RRB)
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

void		insort_(t_arr *fi)
{
	t_op	path;
	t_op	ins;

	ins = top_fil();
	while (fi->bsz)
	{
//		print_arr_s(fi, "NEW");
		path = compute_path(fi, ins);
		execute(fi, path, -1);
	}
//	print_arr_s(fi, "END");
	rstack(fi, EMP);//	print_arr_s(fi, "ENN");
}
