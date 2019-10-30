/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:52:32 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/17 21:27:16 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

/*
**take 1 el of b - check steps R in A -> R then PA
*/

long		b_check(t_arr *fi)
{
	long	bz;

	bz = fi->bsz;
	if (fi->bsz < 2)
		return (-0);
	if (fi->bst[bz - 1] > fi->ast[fi->asz - 1] && fi->bst[bz - 1] < fi->ast[0])
	{
		revrot(&fi->bst, fi->bsz);
		print_com(RRB);
		return (RRB);
	}
	return (0);
}

long		still_check(t_arr *fi, long i, long j)
{
	if (i == fi->asz)
	{
		rstack(fi);//
		print_arr_s(fi, "afrs");
		push_b_r(&fi->bst, &fi->ast, &fi->bsz, &fi->asz);
		print_com(PA);
		if ((j = isort(fi)) != EMP && j != LOL)
			rstack(fi);
		return (0);
	}
	--i;
	if (i >= fi->asz / 2)
	{
		rstack(fi);//
		if (isort(fi) != LOL)
			revrot(&fi->ast, fi->asz);
		print_com(RRA);
		return (0);
	}
	else if (i < fi->asz / 2)//
	{
		if (isort(fi) == LOL)
			rstack(fi);
		rot_a(&fi->ast, fi->asz, 1);
		return (0);
	}
	return (1);
}
long		i_check(t_arr *fi, long i)//7 9 1 11 4 5 6 3 2 8 10
{
	if (!i)
	{
		if (fi->bsz > 0)
		{
			push_b_r(&fi->bst, &fi->ast, &fi->bsz, &fi->asz);
			print_com(PA);
		}
		if (fi->bsz && fi->bst[0] > fi->ast[fi->asz - 1])
			return (-0);
		if (isort(fi) != EMP && isort(fi) != LOL)
			rstack(fi);
		return (0);
	}
	return (1);
}
long		check_place(t_arr *fi)
{
	long i;
	long j;

	i = 0;
	j = 0;
	b_check(fi);
	while (i < fi->asz && fi->bst[0] > fi->ast[i])
		++i;
	long t; t = i_check(fi, i );
	if (t != 0 && t != -0)	//	if (i_check(fi, i) != 0 || i_check(fi, i ) != -0);
		still_check(fi, i , j);
	//i_check(fi, i);
	//return (still_check(fi, i, j));
}

void		insort(t_arr *fi)
{
	while (1)
	{
		print_arr_s(fi, "ins");
		if (!fi->bsz)// && isort(fi) != LOL && isort(fi) != EMP)
		{
			if (isort(fi) == LOL)
				rstack(fi);
			print_arr_s(fi, "rs");
			if (isort(fi) != LOL && isort(fi) != EMP)
				break ;
		}
		//	break ;
		if (check_place(fi))
		{
			if (isort(fi) == LOL)
			{
				rstack(fi);
			}
		}
	}
}
