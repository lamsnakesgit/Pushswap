/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:14:47 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/29 20:14:50 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_arr		*init_date(long *src, long ac)
{
	t_arr	*fi;

	fi = (t_arr *)ft_memalloc(sizeof(t_arr));
	fi->ast = (long *)src;
	if (!(fi->bst = ft_memalloc(ac * sizeof(long))))
		return (0);
	fi->asz = ac;
	fi->bsz = 0;
	fi->alls = ac;
	return (fi);
}

void		freec(t_arr *fi)
{
	free((void *)(fi->ast));
	free((void *)(fi->bst));
	free(fi);
}

int			wtf(long *src, long rg)
{
	long	j;
	t_arr	*fi;

	if (!(fi = init_date(src, rg)))
		return (0);
	j = isort(fi);
	while (fi->asz > 3 && ((j = isort(fi)) == EMP || j == LOL))
	{
		push_b_r(&fi->ast, &fi->bst, &fi->asz, &fi->bsz);
		print_com(PB);
	}
	if (fi->asz == 3)
		ch_a(fi->ast, fi->asz);
	insort_(fi);
	freec(fi);
	return (1);
}
