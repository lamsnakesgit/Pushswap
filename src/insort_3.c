/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insort_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:11:34 by ddratini          #+#    #+#             */
/*   Updated: 2019/11/16 17:12:19 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

long		get_imaxmin(long *arr, long size, long f, long tmp)
{
	long i;
	long item;

	i = 0;
	item = 0;
	tmp = arr[0];
	if (f > 0)
	{
		while (++i < size)
			if (arr[i] > tmp)
			{
				item = i;
				tmp = arr[i];
			}
	}
	else
	{
		while (++i < size)
			if (arr[i] < tmp)
			{
				item = i;
				tmp = arr[i];
			}
	}
	return (item);
}

long		coma_isearch(t_arr *fi, long i, long f)
{
	long k;
	long mid;

	k = 0;
	if (f == 1)
	{
		mid = 0;
		while (k < fi->asz && fi->bst[i] < fi->ast[k])
			++k;
		while (k < fi->asz && fi->bst[i] > fi->ast[k])
			++k;
		while (mid < fi->asz && fi->bst[i] < fi->ast[mid])
			++mid;
		if (k == fi->asz)
			return (-1);
	}
	else
	{
		while (k < fi->asz && fi->bst[i] > fi->ast[k])
			++k;
	}
	return (k);
}

long		round_or_plain(t_arr *fi, long i)
{
	long maxi;
	long mini;
	long ink;

	maxi = get_imaxmin(fi->ast, fi->asz, 1, fi->ast[0]);
	mini = get_imaxmin(fi->ast, fi->asz, -1, fi->ast[0]);
	if (mini > maxi)
		ink = coma_isearch(fi, i, 1);
	else
		ink = coma_isearch(fi, i, 0 - 1);
	ink = ink < 0 ? 0 : ink;
	ink = fi->bst[i] < fi->ast[mini] || fi->bst[i] > fi->ast[maxi] ? mini : ink;
	return (ink);
}

t_op		top_fil(void)
{
	t_op ins;

	ins.asp = -1;
	ins.adr = -1;
	ins.bdr = -1;
	ins.bsp = -1;
	ins.total = -1;
	ins.rr = 0;
	ins.rrr = 0;
	ins.rram = 0;
	ins.rrram = 0;
	return (ins);
}
