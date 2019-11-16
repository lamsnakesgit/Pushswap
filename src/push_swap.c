/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:14:01 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/18 21:28:28 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_swap(char **m, char **b)
{
	char *t;

	t = *m;
	*m = *b;
	*b = t;
}

/*
** validate that argumenats are digit strings
** save  avs int o int s
** after dup check-int; save into a linked list??
** space for push>
** remallc;
*/

int		main(int ac, char **av)
{
	char *sp;

	if (av[1] && ac > 1)
	{
		sp = ft_strchr(av[1], ' ');
		if (sp && ac > 2)
			ft_err();
		if (ac == 2 && sp)
		{
			check_i(ac - 1, av + 1, +1);
		}
		else if ((ac == 2 && !sp) || (ac > 2 && !sp))
			if (validate(ac, av + 1, -1))
			{
				if (ac == 2 && !ft_strchr(av[1], ' '))
					exit(0);
				if (check_i(ac - 1, av + 1, +1) == -4)
					ft_err();
			}
	}
	return (0);
}
