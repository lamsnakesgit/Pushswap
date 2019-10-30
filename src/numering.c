/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:08:08 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/13 15:33:10 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void			rotate_push_b_r(int *ast, int *bi, int it)
{
	int i;
	int fa;
	int j;

	if (bi)
		free(bi);
	if (!bi)
		bi = (int *)malloc(sizeof(int) * it);
	if (!bi)
		return ;
	i = 0;
	fa = ast[0];
	j = 0;
	while (++i < it)
	{
		bi[j] = ast[i];
		++j;
	}
}

void			push_b_r(long **ast, long **bi, long int *sza, long int *szb)
{
	long int	i;
	long		fsz;
	long		wsz;

	i = 0;
	if (*sza - 1 < 0)
		return ;
	fsz = --*sza;
	wsz = ++*szb;
	if (bi && *bi)
	{
		while (--wsz > 0)
			(*bi)[wsz - 1 + 1] = (*bi)[wsz - 2 + 1];
		(*bi)[0] = (*ast)[0];
	}
	if (!ast || !*ast)
		return ;
	i = -1;
	while (++i < *sza)
		(*ast)[i] = (*ast)[i + 1];
}

long int		search_minmax(long *arr, long size, long inorax)
{
	long int	i;
	long int	min;
	long int	max;

	i = -1;
	if (!arr)
		return (__LONG_MAX__);
	if (inorax == -1)
	{
		min = arr[0];
		while (++i < size)
		{
			if (min > arr[i])
				min = arr[i];
		}
		return (min);
	}
	if ((i = -1))
		max = arr[0];
	while (++i < size)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return (max);
}

int				rot_a(long **arr, long size, long mas)
{
	int i;
	int rta;

	i = -1;
	rta = (*arr)[0];
	while (++i < size - 1)
	{
		(*arr)[i] = (*arr)[i + 1];
	}
	(*arr)[i] = rta;
	if (mas == 1)
		print_com(RA);
	else if (mas == 2)
		print_com(RB);
	return (0);
}

int				revrot(long **arr, long size)
{
	int i;
	int rra;

	i = 0;
	rra = (*arr)[size - 1];
	while (--size > 0)
	{
		(*arr)[size] = (*arr)[size - 1];
	}
	(*arr)[size] = rra;
	return (1);
}
