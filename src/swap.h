/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <ddratini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:51:33 by ddratini          #+#    #+#             */
/*   Updated: 2019/11/08 17:18:20 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <fcntl.h>
# define EMP 2222000000
# define SA 1
# define SB 2
# define SS 3
# define PB 4
# define PA 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define LOL __LONG_MAX__
# define IMINS     2147483648

# define MAX_FD 11000

typedef	struct	s_co
{
	long			op;
	long 			as;
	long 			bs;
	struct s_co		*next;
}				t_co;

typedef	struct	s_arr
{
	long int		*ast;
	long			asz;
	long			*bst;
	long			bsz;
	long			alls;
}				t_arr;
typedef	struct	s_op
{
	long		asp;
	long 		adir;
	long 		bsp;
	long		bdir;
	long 		total;
}				t_op;
typedef	struct	s_inst
{
	long			co;
	long 			n;
	struct s_inst	*next;
}				t_inst;

typedef struct	s_mas
{
	long		*src;
	long		size;
	long		ifsrt;
}				t_mas;

void			ft_err(void);
void			insort(t_arr *fi);
long int		*parse_ar_inti(long int rg, char **av);
int				check_dup(long int rc, long int *src);
int				validate(int ac, char **av);
int				print_com(int cm);

long int		swap_i(long int *l, long int *b);
void			print(long *arr, long size, char *stn);
long int		rsortie(long int rg, long int *bar);
long int		search_minmax(long *arr, long int size, long int inorax);
int				rot_a(long int **arr, long int size, long int mas);
int				revrot(long int **arr, long int size);

long int		sort_(long int rg, long int *src);
int				*recopy_arr(int *stk, int co);

void			push_b_r(long **ast, long **bi, long *sza, long *szb);
int				somewhat(int ac, int *f, int*f1);

long int		issorted(long int *arr, long int size);
int				d(long int *scr, long int *bd, long int rg, long int *b);
int				wtf(long int *src, long int rg);

int				ins(t_arr *fi);
long			gg(long int *src, long int *dop, long int ac, long int *bs);
void			print_arr_s(t_arr *fi, char *stn);
t_co			*scom(t_co *co, int ac);
t_arr			*init_date(long *src, long ac);
void			rstack(t_arr *fi, long n);
long int		isort(t_arr *fi);
int				triad(long *arr, long size);
int				check_i(int ac, char **av, int pc);
int				dup_parse(long **src, int ac, char **av);
int				free_err(long *arr);

long			valsp(char *av, long *sg);
long			*parse_i(char *av, long int *sz);
void			freec(t_arr *fi);
/*
**uni2 fterr
** d2
** c2
** c3
*/
int				free_err(long *arr);
long int		issorted(long *arr, long size);
int				dup_parse(long **src, int ac, char **av);
int				ret_al(long *src, int ac);
long			out_max(long int res, long sg, char av);

t_arr			*init_date(long *src, long ac);
void			freec(t_arr *fi);

int				compare(char *line);
int				ch_err(t_inst *com, t_mas srt, int code);
long			rotator(t_inst *com, t_arr *fi);
long			push_swap(t_inst *com, t_arr *fi);

int				exec(t_inst *com, t_mas srt);

long			corr_inst(t_inst *com);
long			count_node(t_inst *com);
void			free_lst(t_inst *com);
t_inst			*com_fil(t_inst **com, long inst, long n);
void			revstack(t_arr *fi, long n);

long			b_check(t_arr *fi);
long			i_check(t_arr *fi, long i);
long			find_p(t_arr *fi);
long			check_place(t_arr *fi);

void		insort_(t_arr *fi);

#endif
