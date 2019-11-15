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
t_inst		*up_stack(t_arr *fi, t_inst *com, long i)
{
	long    cnt;
    t_inst  *min;

	cnt = -1;
	if (i <= fi->bsz / 2)//(fi->bst[i]);
	{
		while (++cnt < i)
			com_fil(&com, RB, fi->bst[i]);
	}
	else
	{
		while (fi->bsz - ++i > 0)// - 1 > 0)//(--i - 1 > 0)//(++cnt < i - 1)//!?
			com_fil(&com, RRB, fi->bst[i]);
	}
	return (com);//(*com);
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
long		coma_isearch(t_arr *fi, long i, long f)//lokinf atually for a place
{
	long k;
//if b[i] > all in A just Push? 0 moves//if k == fi->asz?
	k = 0;
	if (f == 1)//(mini > maxi)//(maxi > mini)
	{
		while (k < fi->asz && fi->bst[i] < fi->ast[k])// && ++k)
			++k;//for round s
		while (k < fi->asz && fi->bst[i] > fi->ast[k])//if (fi->bst[i] > fi->ast[k])
				++k;//till round circel circle
	}
	else
	{
		while (k < fi->asz && fi->bst[i] > fi->ast[k])
			++k;
	}
	return (k);
}
t_inst      *get_toplace(t_arr *fi, long i)
{
	long j;//stack A
	long maxi;
	long mini;
	long k;
//detedting if stack A is tround or plain
	maxi = get_imaxmin(fi->ast, fi->asz, 1);
	mini = get_imaxmin(fi->ast, fi->asz, -1);
	k = 0;
	if (mini > maxi)//(maxi > mini)
		k = coma_isearch(fi, i, 1);
	else//prob rev ert
		k = coma_isearch(fi, i, 0-1);
	if (k <= fi->asz / 2)
		while (++k <= i)
			//com_fil(&com, RA, fi->bst[i]);
	else
		while (--k >= i)
			//com_fil(&com, RRA, fi->bst[i]);
	return (0);//
}
t_op		*compute_path(t_arr *fi)//, t_op *com)//ins
{
	t_op	p;
	long	i;
	t_op	min;//*min;
	long	m;

	i = 0;//way home - lol
	i = -1;//exah each time save comline s//then free
	while (++i < fi->bsz)//collecting the path-ways and saving the minimum
	{
	//	com = 0;//saving minimalss
    	if (i == 0)//1)
		{
    		min = 0;//com;
    		m = 0;//com->n;
		}//get top place returns theminimal movemnts in A for B-el //up_st ret min-move for B to-ptop
		get_toplace(fi, i);//init co here///last- PA
		up_stack(fi, com, i);//filling the node with operations till up_Bstack
    	free_lst(com);
	}
	return (min);
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
void		insort_(t_arr *fi)
{
	t_op	*com;
//	t_inst	*path;
	t_co	*ins;

	ins = 0;
	com = 0;
	while (fi->bsz)
	{
		print_arr_s(fi, "NEW");
		path = compute_path(fi, com);//calc
		//exec(com, fi);//insertung//rotcir
//		free_lst(path);//com);//&
		break ;
	}
}