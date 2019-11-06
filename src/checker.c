/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 20:20:46 by ddratini          #+#    #+#             */
/*   Updated: 2019/10/29 16:35:46 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

long		com_check(t_inst *com, t_mas srt)
{
	long cnt;
	long fck;

	cnt = count_node(com);
	fck = corr_inst(com);
	if (fck == -12)
	{
		if (issorted(srt.src, srt.size) == LOL)
			write(1, "OK\n", 3);
		else
			write(1, "\n", 1);
		return (1);
	}
	if ((fck = corr_inst(com)) < 0)
		ch_err(com, srt, 4);
	exec(com, srt);
	free_lst(com);
	return (0);
}

t_inst		*command_s(void)
{
	char	*line;
	t_inst	*com;
	int		in;
	int		i;

	com = 0;
	i = 0;int fd = open("/Users/ddratini/42_03_projests/Push_swap/INSORT/t", O_RDONLY);//fd = 0;
	while (get_next_line(fd, &line) > 0)
	{
		in = compare(line);
		free(line);
		com_fil(&com, in);
		++i;
	}
	return (com);
}

t_mas		checkf(int ac, char **av)
{
	long	chd;
	t_mas	srt;
	t_inst	*com;

	chd = 0;
	srt.size = ac;
	if (ac == 1 && ft_strchr(av[0], ' '))
	{
		srt.size = 2;
		if ((srt.src = parse_i(av[0], &srt.size)) == 0)
			ft_err();
		chd = 1;
	}
	else
		srt.src = parse_ar_inti(srt.size, av);
	srt.ifsrt = 0;
	if (chd && issorted(srt.src, srt.size) == LOL)
		srt.ifsrt = 1;
	else if (!chd && issorted(srt.src, ac) == LOL)
		srt.ifsrt = 1;
	com = command_s();
	com_check(com, srt);
	return (srt);
}

static int	check_it(int ac, char **av, long **src)
{
	long szs;
	long chd;

	szs = 2;
	chd = 0;
	if (ac == 1 && ft_strchr(av[0], ' '))
	{
		if ((*src = parse_i(av[0], &szs)) == 0)
			ft_err();
		chd = 1;
	}
	else
		*src = parse_ar_inti(ac, av);
	if (ac > 1 || chd)
		chd ? check_dup(szs, *src) : check_dup(ac, *src);
	free(*src);
	return (1);
}

int			main(int ac, char **av)
{
	char *sp;
	long *src;

	src = 0;
	if (av[1] && ac > 1)
	{
		sp = ft_strchr(av[1], ' ');
		if (sp && ac > 2)
			ft_err();
		if (ac == 2 && sp)
		{
			check_it(ac - 1, av + 1, &src);
			checkf(ac - 1, av + 1);
		}
		else if ((ac == 2 && !sp) || (ac > 2 && !sp))
			if (validate(ac, av + 1))
			{
				if (check_it(ac - 1, av + 1, &src) == -4)
					ft_err();
				checkf(ac - 1, av + 1);
			}
	}
	return (0);
}
