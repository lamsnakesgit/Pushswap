#include "swap.h"

long	find_p(t_arr *fi)
{
	long i;

	i = 0;
	while (i < fi->asz && fi->bst[0] > fi->ast[i])
		++i;
	return (i);
}/*
int		check_place(t_arr *fi)
{
	long j;
	long i;
	long t;

	j = 0;
	b_check(fi);
	i = find_p(fi);
	t =  i_check(fi, i, );
	return (0);

}*/ /*
long	analyse_st(t_arr *fi)
{
	if ()
	{
		;
	}//
}*/
void	insort(t_arr *fi)
{
	while (fi->bsz > 0)// && issorted(fi->ast, fi->asz) != LOL)
	{
		print_arr_s(fi, "Ins");
		check_place(fi);
	}
}
/*
void		count_iter(t_arr *fi)
{

}*/
/* check stack_B leava acom// every element to get tot top
 ** check every element how muchi tales to get up;
 *  every el's index --> amunt of rotations
*//*
t_inst		*up_stack(t_arr *fi, t_inst **ins)
{
	long i;
	long cnt;

	i = 0;
	while (++i < fi->bsz)
	{
		cnt = -1;
		if (i <= fi->bsz / 2)//(fi->bst[i]);
		{
			while (++cnt < i)
				com_fil(&com, RB);
		}
		else
		{
			while (++cnt < i)
				com_fil(&com, RRB);
		}
	}
	return (0);
}*//*
t_inst		*compute_path(t_arr *fi, t_inst *ins)
{
	t_inst p;

	up_stack(fi, &ins);
//	return
}

void		insort_(t_arr *fi)
{
	t_inst *com;

//	com = com_fil(&com, 0);
//	compute_path(fi, com);
}*/