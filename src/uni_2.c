/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:15:03 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/29 20:15:05 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int				free_err(long *arr)
{
	free(arr);
	return (-4);
}

long int		issorted(long *arr, long size)
{
	long int i;

	i = 0;
	while (++i < size)
	{
		if (arr[i] < arr[i - 1])
			return (i);
	}
	return (LOL);
}

int				dup_parse(long **src, int ac, char **av)
{
	*src = parse_ar_inti(ac, av);
	if (ac > 1)
		check_dup(ac, *src);
	if (issorted(*src, ac) == LOL)
		return (free_err(*src));
	return (3);
}

int				ret_al(long *src, int ac)
{
	if (ac == 2 && src[0] > src[1])
	{
		swap_i(src + 1, src);
		print_com(SA);
		free(src);
		return (1);
	}
	else
	{
		if (wtf(src, ac))
			return (1);
	}
	return (0);
}

long			out_max(long int res, long sg, char av)
{
	if ((((res * 10) + (av - '0')) * 10) / 10 != (res * 10) + (av - '0'))
		return (0);
	if (res > INT32_MAX && sg == 1)
		return (0);
	if (res > IMINS && sg == -1)
		return (0);
	return (1);
}
