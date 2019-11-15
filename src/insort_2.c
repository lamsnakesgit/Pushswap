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
/*t_inst      *count_till_top(t_arr *fi, t_inst **com)
{
}*/
/*while (--i - 1 > 0)//(++cnt < i - 1)//!?*/
long		up_stack(t_arr *fi, t_op *ins, long i)
{
	long    cnt;
    t_inst  *min;

	cnt = -1;
	if (i <= fi->bsz / 2)//(fi->bst[i]);
	{
		ins->bsp = i;
		ins->bdir = RA;
	//	while (++cnt < i)
			//com_fil(ins, RB, fi->bst[i]);
	}
	else
	{
		ins->bsp = fi->bsz - i;
		ins->bdir = RRA;
	//	while (fi->bsz - ++i > 0)// - 1 > 0)//(--i - 1 > 0)//(++cnt < i - 1)//!?
			//com_fil(ins, RRB, fi->bst[i]);
	}
	return (ins->bsp);//com);//(*com);
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
/*
 * 5 0
 * 1 45
 * 2
 * 3
 * */
long		coma_isearch(t_arr *fi, long i, long f, long mx)//lokinf atually for a place
{
	long k;
	long mid;

//if b[i] > all in A just Push? 0 moves//if k == fi->asz?
	k = 0;
	if (f == 1)//(mini > maxi)//(maxi > mini)
	{
		mid = 0;
		while (k < fi->asz && fi->bst[i] < fi->ast[k])// && ++k)
			++k;//for round s
		while (k < fi->asz && fi->bst[i] > fi->ast[k])//if (fi->bst[i] > fi->ast[k])
				++k;//till round circel circle
		while (mid < fi->asz && fi->bst[i] < fi->ast[mid])//if round-> max in mid
			++mid;//if its biggest -> its placi is in mid m->maxin
		if (k == fi->asz)
			return (mx);///-2);
	}
	else
	{
		while (k < fi->asz && fi->bst[i] > fi->ast[k])
			++k;
	}
	return (k);
}
/*void		save_op(t_op *ins, t_arr *fi,  long ink)
{
	if (ink <= fi->asz / 2)
	{
		if (ink < 0)
			ins->asp = maxi
	}
}*/
//t_inst      *
long		get_toplace(t_arr *fi, long i, t_op *ins)//find place & count operaa
{
	long j;//stack A
	long maxi;
	long mini;
	long ink;//least/biggest in plain -> just PA 0op
//detedting if stack A is tround or plain
	maxi = get_imaxmin(fi->ast, fi->asz, 1);
	mini = get_imaxmin(fi->ast, fi->asz, -1);
	ink = mini > maxi ? coma_isearch(fi, i, 1, maxi) : coma_isearch(fi, i , 0-1, maxi);//if (mini > maxi)//(maxi > mini)
//		ink = coma_isearch(fi, i, 1);//	else//prob rev ert//		ink = coma_isearch(fi, i, 0-1);
	if (ink <= fi->asz / 2)
	{//lest of all in circle?
		ins->asp = /*ink < 0 ? maxi :*/ ink;//while (++k <= i)
		ins->adir = RA;//com_fil(&com, RA, fi->bst[i]);
	}
	else
	{//if predposl?
	//	while (--ink >= i)
		ins->adir = RRA;
		ins->asp = ink == fi->asz ? 0 : fi->asz - ink;
	}
	return (ins->asp);//
}
t_op		/**/compute_path(t_arr *fi, t_op ins)//, t_op *com)//ins
{
//	t_op			p;
	long			i;
	unsigned long	min;//*min;
	t_op			mins;//t_op			ins;
	long 			aop;
	long 			bop;

	i = 0;//way home - lol
	i = -1;//exah each time save comline s//then free
	min = LOL + 1;
//	mins = LOL + 1;
	while (++i < fi->bsz)//collecting the path-ways and saving the minimum
	{
	//	com = 0;//saving minimalss
    	if (i == 0)//1)
			mins = ins;//com;
	//		min = 0;//com->n;
		//get top place returns theminimal movemnts in A for B-el //up_st ret min-move for B to-ptop
		aop = get_toplace(fi, i, &ins);//init co here///last- PA
		bop = up_stack(fi, &ins, i);//filling the node with operations till up_Bstack
	//	free_lst(ins);
		if ((ins.total = aop + bop + 1) < min)//s)
		{
			mins = ins;//aop;
			min = aop + bop + 1;//
		}
	}
	return (mins);//(ins);//min);
}

t_op		top_fil(t_op ins)
{
	ins.asp = -1;
	ins.adir = -1;
	ins.bdir = -1;
	ins.bsp = -1;
	ins.total = -1;
	return (ins);
}
static void	execute(t_arr *fi, t_op ins, long i)
{
	i = -1;
	if (ins.adir == RA)
		while (++i < ins.asp)
			rot_a(&fi->ast, fi->asz, 1);
	i = -1;
	if (ins.adir == RRA)
		while (++i < ins.asp)
		{
			revrot(&fi->ast, fi->asz);//	rot_a(&fi->ast, fi->asz, 1)
			print_com(RRA);

		}
	i = -1;
	if (ins.bdir == RB)
		while (++i < ins.bsp)
			rot_a(&fi->bst, fi->bsz, 2);
	i = -1;
	if (ins.bdir == RRB)
		while (++i < ins.bsp)
		{
			revrot(&fi->bst, fi->bsz);
			print_com(RRB);
		}
	push_b_r(&fi->bst, &fi->ast, &fi->bsz, &fi->asz);
	print_com(PA);
}
void		insort_(t_arr *fi)
{
	t_op	*com;
//	t_inst	*path;
/*	t_co*/
	t_op	path;
	t_op	ins;

	ins = top_fil(ins);
	com = 0;
	while (fi->bsz)
	{
	//	print_arr_s(fi, "NEW");
		path = compute_path(fi, ins);//calc
		execute(fi, path, -1);
		//exec(com, fi);//insertung//rotcir
//		free_lst(path);//com);//&
	//	break ;
	}
	rstack(fi,)
}
/*t_co		*com_save(t_co **com, long ins)
{
	t_co *h;
	t_co *tmp;

	if (!*com)
	{
		(*com) = (t_co *)malloc(sizeof(t_co));
		(*com)->op = ins;
		(*com)->next = 0;
		h = (*com);
	}
	else
	{
		h = *com;
		tmp = *com;
		while (tmp)
			tmp = tmp->next;
		tmp = (t_co *)malloc(sizeof(t_co));
		tmp->op = ins;
		tmp->next = 0;
	}
	return (h);
}*/