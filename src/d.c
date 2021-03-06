/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:59:24 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/17 19:24:33 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int			ch_a(long *arr, long size)
{
	long int i;

	i = 0;
	while (++i < 3)
	{
		if (issorted(arr, size) == __LONG_MAX__)
			return (1);
		if (triad(arr, size))
		{
			revrot(&arr, size);
			print_com(RRA);
		}
	}
	return (1);
}

int			triad(long *arr, long size)
{
	if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] > arr[2])
	{
		swap_i(arr, arr + 1);
		print_com(SA);
		revrot(&arr, size);
		print_com(RRA);
	}
	else if (arr[0] > arr[1] && arr[0] > arr[2] && arr[1] < arr[2])
		rot_a(&arr, size, 1);
	else if (arr[0] > arr[1] && arr[0] < arr[2])
	{
		swap_i(arr, arr + 1);
		print_com(SA);
	}
	else if (arr[0] < arr[1] && arr[0] < arr[2])
	{
		revrot(&arr, size);
		print_com(RRA);
		swap_i(arr, arr + 1);
		print_com(SA);
	}
	else
		return (1);
	return (0);
}

long int	isort(t_arr *fi)
{
	int		i;
	int		n;
	long	s;

	n = 0;
	i = 0;
	while (++i < fi->asz)
	{
		if (fi->ast[i - 1] > fi->ast[i])
		{
			s = i;
			if (++n == 2)
				return (EMP);
		}
	}
	if (n == 1 && fi->ast[0] < fi->ast[i - 1])
		return (LOL);
	return (s);
}

void		revstack(t_arr *fi, long n)
{
	long sv;
	long mar;
	long ru;

	ru = 0;
	while (n > fi->ast[ru])
		++ru;
	mar = isort(fi);
	if (mar != EMP && mar != LOL)
	{
		sv = fi->ast[ru];
		--ru;
		while (mar && fi->ast[0] != sv)
		{
			if (ru <= fi->asz / 2)
			{
				revrot(&fi->ast, fi->asz);
				print_com(RRA);
			}
			else
				rot_a(&fi->ast, fi->asz, 1);
		}
	}
}

void		rstack(t_arr *fi, long n)
{
	long s;
	long mar;
	long min;

	if (n < fi->ast[fi->asz - 1] && issorted(fi->ast, fi->asz) == LOL)
		return ;
	if (n != EMP)
		revstack(fi, n);
	s = isort(fi);
	if (s != EMP && s != LOL)
	{
		mar = s;
		min = search_minmax(fi->ast, fi->asz, -1);
		while (s && fi->ast[0] != min)
		{
			if (mar <= fi->asz / 2)
				rot_a(&fi->ast, fi->asz, 1);
			else
			{
				revrot(&fi->ast, fi->asz);
				print_com(RRA);
			}
		}
	}
}
