/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:41:06 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/17 20:31:56 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void			ft_err(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int				check_dig(char *av, int fn)
{
	int		i;
	char	*maxi;
	char	*mini;
	int		cmpr;

	i = -1;
	maxi = "2147483647";
	mini = "-2147483648";
	if (!fn && (cmpr = ft_strcmp(av, maxi)) > 0)
		ft_err();
	else if (fn && ft_strcmp(av, mini) > 0)
		ft_err();
	else
		return (1);
	return (0);
}

int				validate(int ac, char **av)
{
	int		i;
	int		j;
	long	fn;
	size_t	len;

	i = -1;
	while (av[++i] && i < ac - 1)
	{
		fn = 0;
		j = -1;
		if (av[i][0] == '-')
			fn = 1;
		if ((len = ft_strlen(av[i])) > 11 || (len > 10 && !fn))
			ft_err();
		while (av[i][++j])
		{
			if (fn && !j)
				++j;
			if (!valsp(av[i] + j, &fn))
				ft_err();
			if ((j >= 10) || (j >= 9 && !fn))
				check_dig(av[i], fn);
		}
	}
	return (1);
}

long int		*parse_ar_inti(long int rg, char **av)
{
	long int *arr;
	long int i;

	if (!(arr = (long int *)malloc(sizeof(long int) * rg)))
		return (0);
	i = 0;
	while (rg)
	{
		arr[i] = ft_atoi(av[i]);
		++i;
		--rg;
	}
	return (arr);
}

int				check_dup(long int rc, long int *src)
{
	long int i;
	long int dp;
	long int j;

	i = -1;
	while (++i < rc)
	{
		dp = src[i];
		j = i;
		while (++j < rc)
		{
			if (dp == src[j])
			{
				free(src);
				ft_err();
			}
		}
	}
	return (1);
}
