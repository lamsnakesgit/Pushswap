/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:52:11 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/17 20:22:29 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

long			valsp(char *av, long *sg)
{
	if (*av == '-')
		*sg = -1;
	if ((*av == ' ' && (*(av + 1) == ' ' || !*(av + 1))) \
	|| ((*av == '-' || *av == '+') && !ft_isdigit(*(av + 1))) \
	|| (*av != ' ' && *av != '-' && *av != '+' && !ft_isdigit(*av)))
		return (0);
	return (1);
}

long			*rec(long *res, long *sg, long *src, long *i)
{
	(src)[*i] = *res * *sg;
	*res = 0;
	*sg = 1;
	(*i)++;
	return (src);
}

long			count_nul(char *av, long int *sz)
{
	char *sub;

	sub = ft_strchr(av, ' ');
	while ((sub = ft_strchr(sub + 1, ' ')))
		++*sz;
	return ((int)*sz);
}

long			*parse_i(char *av, long int *sz)
{
	long *src;
	long i;
	long res;
	long sg;

	i = 0;
	src = (long *)malloc(sizeof(long) * count_nul(av, sz));
	sg = 1;
	res = 0;
	while (*av)
	{
		if (ft_isdigit(*av))
			res = (res * 10) + (*av - '0');
		if (!valsp(av, &sg))
			return (free_err(src) == -4 ? NULL : 0);
		if (!out_max(res, sg, *av))
			return (free_err(src) == -4 ? NULL : 0);
		if (*av == ' ' || !*(av + 1))
			rec(&res, &sg, src, &i);
		++av;
	}
	out_max(res, sg, *av);
	return (src);
}

int				check_i(int ac, char **av, int pc)
{
	long *src;
	long szs;
	long chd;

	src = 0;
	szs = 2;
	chd = 0;
	if (ac == 1 && ft_strchr(av[0], ' '))
	{
		if ((src = parse_i(av[0], &szs)) == 0)
			ft_err();
		chd = 1;
	}
	else
		src = parse_ar_inti(ac, av);
	if (ac > 1 || chd)
		chd ? check_dup(szs, src) : check_dup(ac, src);
	if (chd && issorted(src, szs) == LOL)
		return (free_err(src));
	else if (!chd && issorted(src, ac) == LOL)
		return (free_err(src) < 0 ? 1 : 0);
	if (pc == 2)
		return (1);
	else
		return (chd > 0 ? ret_al(src, szs) : ret_al(src, ac));
}
