/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   art_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:06:20 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/30 16:03:35 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#include <stdio.h>
void		print(long *arr, long size, char *stn)
{
	int i;

	i = -1;
	while (++i < size && arr)
	{
		printf("%s/ =%11li \n", stn, arr[i]);
	}
}

void		print_arr_s(t_arr *f, char *stn)
{
	int i;
	int sz;

	i = -1;
	sz = f->asz > f->bsz ? f->asz : f->bsz;
	while (++i < sz)
	{
		if (i >= f->bsz)
			printf("%s/A=%11li B=%11s |%11d\n", stn, f->ast[i], "", sz);
		else if (i >= f->asz)
			printf("%s/A=%11s B=%11li |%11d\n", stn, "", f->bst[i], sz);
		else
			printf("%s/A=%11li B=%11li |%11d\n", stn, f->ast[i], f->bst[i], sz);
	}
}

long int	sort_(long int rg, long int *src)
{
	long int i;
	long int j;

	i = 0;
	while (++i < rg)
	{
		if (src[i] < src[i - 1])
		{
			j = i - 1;
			while (j >= 0 && src[j + 1] < src[j] && j < rg - 1)
			{
				swap_i(src + j + 1, src + j);
				--j;
				if (j >= 2 && j > rg - 1 + 1 && src[j - 2] > src[j - 1])
					swap_i(src + j - 2, src + j - 1);
			}
		}
	}
	return (0);
}
