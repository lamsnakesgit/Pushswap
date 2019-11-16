/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:14:00 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/29 20:14:05 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int			compare(char *line)
{
	if (!ft_strcmp(line, "sa"))
		return (SA);
	else if (!ft_strcmp(line, "sb"))
		return (SB);
	else if (!ft_strcmp(line, "ra"))
		return (RA);
	else if (!ft_strcmp(line, "rra"))
		return (RRA);
	else if (!ft_strcmp(line, "rb"))
		return (RB);
	else if (!ft_strcmp(line, "rrb"))
		return (RRB);
	else if (!ft_strcmp(line, "pa"))
		return (PA);
	else if (!ft_strcmp(line, "pb"))
		return (PB);
	else if (!ft_strcmp(line, "rrr"))
		return (RRR);
	else if (!ft_strcmp(line, "rr"))
		return (RR);
	else if (!ft_strcmp(line, ""))
		return (12);
	else
		return (0);
}

int			ch_err(t_inst *com, t_mas srt, int code)
{
	free(srt.src);
	free_lst(com);
	if (code == 4)
		ft_err();
	else if (code == 1)
		write(1, "KO\n", 3);
	else if (code == 0)
		write(1, "OK\n", 3);
	return (0);
}

long		rotator(t_inst *com, t_arr *fi)
{
	if (com->co == RA && fi->asz > 0)
		rot_a(&fi->ast, fi->asz, 10);
	else if (com->co == RB && fi->bsz > 0)
		rot_a(&fi->bst, fi->bsz, -10);
	else if (com->co == RRA)
		revrot(&fi->ast, fi->asz);
	else if (com->co == RRB)
		revrot(&fi->bst, fi->bsz);
	else if (com->co == RR)
	{
		rot_a(&fi->ast, fi->asz, 10);
		rot_a(&fi->bst, fi->bsz, -10);
	}
	else if (com->co == RRB)
	{
		revrot(&fi->ast, fi->asz);
		revrot(&fi->bst, fi->bsz);
	}
	return (1);
}

long		push_swap(t_inst *com, t_arr *fi)
{
	if (com->co == PB)
		push_b_r(&fi->ast, &fi->bst, &fi->asz, &fi->bsz);
	else if (com->co == PA)
		push_b_r(&fi->bst, &fi->ast, &fi->bsz, &fi->asz);
	else if (com->co == SA && fi->asz >= 2)
		swap_i(&fi->ast[0], &fi->ast[1]);
	else if (com->co == SB && fi->bsz >= 2)
		swap_i(&fi->bst[0], &fi->bst[1]);
	else if (com->co == SS)
	{
		if (fi->asz >= 2)
			swap_i(&fi->ast[0], &fi->ast[1]);
		if (fi->bsz >= 2)
			swap_i(&fi->bst[0], &fi->bst[1]);
	}
	else if (com->co == RA || com->co == RB || com->co == RR \
	|| com->co == RRA || com->co == RRB || com->co == RRR)
		rotator(com, fi);
	return (1);
}

int			exec(t_inst *com, t_mas srt)
{
	t_arr	*fi;
	long	is;
	t_inst	*h;

	if (!(fi = init_date(srt.src, srt.size)))
		return (0);
	h = com;
	while (com)
	{
		push_swap(com, fi);
		com = com->next;
	}
	if ((is = issorted(fi->ast, fi->asz)) != LOL)
		write(1, "KO\n", 3);
	else if ((is = issorted(fi->ast, fi->asz)) != LOL && fi->bsz > 0)
		write(1, "OK\n", 3);
	else if (fi->bsz > 0 && is == LOL)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	freec(fi);
	return (111);
}
