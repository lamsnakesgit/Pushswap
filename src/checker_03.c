/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:13:45 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/29 20:13:56 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_inst		*com_fil(t_inst **com, long inst, long n)
{
	t_inst *tmp;
	t_inst *h;

	if (!*com)
	{
		*com = (t_inst *)ft_memalloc(sizeof(t_inst ));
		(*com)->co = inst;
        (*com)->n = n;
		(*com)->next = NULL;
		h = *com;
	}
	else
	{
		h = *com;
		tmp = *com;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_memalloc(sizeof(t_inst ));
		tmp = tmp->next;
		tmp->co = inst;
		tmp->n = n;
		tmp->next = NULL;
	}
	return (h);
}

void		free_lst(t_inst *com)
{
	t_inst *tmp;

	while (com)
	{
		tmp = com->next;
		free(com);
		com = tmp;
	}
}

long		count_node(t_inst *com)
{
	long sz;

	sz = 0;
	while (com)
	{
		++sz;
		com = com->next;
	}
	return (sz);
}

long		corr_inst(t_inst *com)
{
	t_inst *h;

	h = com;
	while (com)
	{
		if (com->co < 1 || com->co > 11)
		{
			if (com->co == 12)
				return (-12);
			return (-1);
		}
		com = com->next;
	}
	return (4);
}
