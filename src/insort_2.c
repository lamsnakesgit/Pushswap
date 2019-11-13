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
/*void	insort(t_arr *fi)
{
	while (fi->bsz > 0)// && issorted(fi->ast, fi->asz) != LOL)
	{
		print_arr_s(fi, "Ins");
		check_place(fi);
	}
}*/
/*
void		count_iter(t_arr *fi)
{

}*/
/* check stack_B leava acom// every element to get tot top
 ** check every element how muchi tales to get up;
 *  every el's index --> amunt of rotations
 * * *1 create first node and each time check len of list to cmpr w minimum also save the n in node's
 * * **2
*/
t_inst      *count_till_top(t_arr *fi, t_inst **com)
{
}
/*while (--i - 1 > 0)//(++cnt < i - 1)//!?*/
t_inst		*up_stack(t_arr *fi, t_inst **com, long i)
{
	long    cnt;
    t_inst  *min;

	cnt = -1;
	if (i <= fi->bsz / 2)//(fi->bst[i]);
	{
		while (++cnt < i)
			com_fil(com, RB, fi->bst[i]);
	}
	else
	{
		while (fi->bsz - ++i > 0)// - 1 > 0)//(--i - 1 > 0)//(++cnt < i - 1)//!?
			com_fil(com, RRB, fi->bst[i]);
	}
	return (*com);
}
long 		get_imaxmin(long *arr, long size, long f)
{
	long i;
	long item;//	long item;
	long mnmx;

	i = 0;
	item = 0;
	if (f > 0)
	{
		mnmx = arr[0];
		while (++i < size)
		{
			if (arr[i] > mnmx)
				item = i;
		}
	}
	else
	{
		mnmx = arr[0];
		while (++i < size)
		{
			if (arr[i] < mnmx)
				item = i;
		}
	}
	return (item);
}
long		coma(t_arr *fi, t_inst **com, long i, long f)
{
	long k;

	k = 0;
	if (f == 1)//(mini > maxi)//(maxi > mini)
	{
		while (fi->bst[i] < fi->ast[k] && ++k);
		while (k < fi->asz)//(fi->bst[i] > fi->ast[k])
		{
			//	if (fi->bst[i] < fi->ast[k])
			//		++k;
			if (fi->bst[i] > fi->ast[k])
				++k;
		}
	}
	else
	{
		while (k < fi->asz)
		{
			if (fi->bst[i] > fi->ast[k])
				++k;
		}
	}
	return (k);
}
t_inst      *get_toplace(t_arr *fi, t_inst **com, long i)
{
	long j;//stack A
	long maxi;
	long mini;
	long k;

//	maxi = search_minmax(fi->ast, fi->asz, 1);//while ()
//	mini = search_minmax(fi->bst, fi->bsz, -1);
	maxi = get_imaxmin(fi->ast, fi->asz, 1);
	mini = get_imaxmin(fi->ast, fi->asz, -1);
	k = 0;
	if (mini > maxi)//(maxi > mini)
	{
		while (fi->bst[i] < fi->ast[k] && ++k);
		while (k < fi->asz)//(fi->bst[i] > fi->ast[k])
		{
		//	if (fi->bst[i] < fi->ast[k])
		//		++k;
			if (fi->bst[i] > fi->ast[k])
				++k;
		}
	}
	else
	{//prob rev ert
		while (++k < fi->asz && fi->bst[i] > fi->ast[k])
		{
//			if (fi->bst[i] > fi->ast[k])
//				++k;
		}
	}
	return (0);//
}
t_inst		*compute_path(t_arr *fi, t_inst *com)//ins
{
	t_inst	p;
    long	i;
	t_inst  *min;
	long	m;

    i = 0;
    i = -1;
    while (++i < fi->bsz)//collecting the path-ways and saving the minimum
    {
    	com = 0;
    	com = com_fil(&com, 0, LOL);
    	if (i == 0)//1)
		{
    		min = com;
    		m = com->n;
		}
		get_toplace(fi, &com, i);
		up_stack(fi, &com, i);//filling the node with operations till up_Bstack
    	free_lst(com);
	}
	return (com);
}

void		insort_(t_arr *fi)
{
	t_inst *com;
	t_inst *path;

	//com = 0;
	//com = com_fil(&com, 0, LOL);
	while (fi->bsz)
	{
		print_arr_s(fi, "NEW");
		path = compute_path(fi, com);//calc
		//exec(com, fi);//insertung//rotcir
		free_lst(com);//&
		break ;
	}
}