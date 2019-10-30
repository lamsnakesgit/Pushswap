/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_sotr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:57:55 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/30 17:45:52 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"


long int	swap_i(long int *l, long int *b)
{
	long int t;

	t = *l;
	*l = *b;
	*b = t;
	return (1);
}

int			print_com(int cm)
{
	if (cm == 's')
		write(1, "sa\n", 3);
	else if (cm == SA)
		write(1, "sa\n", 3);
	else if (cm == SB)
		write(1, "sb\n", 3);
	else if (cm == SS)
		write(1, "ss\n", 3);
	else if (cm == PB)
		write(1, "pb\n", 3);
	else if (cm == PA)
		write(1, "pa\n", 3);
	else if (cm == RA)
		write(1, "ra\n", 3);
	else if (cm == RB)
		write(1, "rb\n", 3);
	else if (cm == RR)
		write(1, "rr\n", 3);
	else if (cm == RRA)
		write(1, "rra\n", 4);
	else if (cm == RRB)
		write(1, "rrb\n", 4);
	else if (cm == RRR)
		write(1, "rrr\n", 4);
	return (0);
}
