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

}*/
void insort(t_arr *fi)
{
	while (fi->bsz > 0)// && issorted(fi->ast, fi->asz) != LOL)
	{
	//	print_arr_s(fi, "Ins");
		check_place(fi);
	}
}