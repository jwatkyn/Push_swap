/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "checker.h"
# include <stdio.h>

# define MAX 2147483647
# define MIN -2147483648
# define ABS(x) (x < 0 ? -x : x)

# ifndef T_STACK_H
#  define T_STACK_H
typedef struct		s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_moves
{
	char			*move;
	struct s_moves	*next;
}					t_moves;

typedef struct		s_info
{
	int				min;
	int				max;
	int				min_count;
	int				dir;
	int				sizeA;
	int				sizeB;
	t_stack			*A;
	t_stack			*B;
	t_moves			*moves;
}					t_info;
# endif

t_stack			*ft_getinfo(char** tab, int count, t_stack *A);
int				*ft_checkinfo(char **tab, int count);
int				*ft_intarray(char **tab, int count);
void			ERROR(void);
t_stack			*add_end(t_stack *head, int val);
t_stack			*create(int val);
int				is_sorted(t_stack *head, int dir);
t_stack			*add_begin(t_stack *head, int val);
t_stack			*del_end(t_stack *head);
t_stack			*del_begin(t_stack *head);
t_stack			*sort(t_stack *A, t_stack *B, t_info *info);
t_stack			*ft_sa(t_stack *A, t_info *info);
t_stack			*ft_sb(t_stack *B, t_info *info);
t_stack			*ft_ss(t_stack **A, t_stack *B, t_info *info);
t_stack			*ft_pa(t_stack *A, t_stack **B, t_info **info);
t_stack			*ft_pb(t_stack *B, t_stack **A, t_info **info);
t_stack			*ft_ra(t_stack *A, t_info *info);
t_stack			*ft_rb(t_stack *B, t_info *info);
t_stack			*ft_rr(t_stack **A, t_stack *B, t_info *info);
t_stack			*ft_rra(t_stack *A, t_info *info);
t_stack			*ft_rrb(t_stack *B, t_info *info);
t_stack			*ft_rrr(t_stack **A, t_stack *B, t_info *info);
t_stack			*quicksort(t_stack *A, t_stack *B, t_info *info);
void			free_array(char **array);
void			free_list(t_stack *A);
t_stack			*large_sort(t_stack *A, t_stack *B, t_info *info);
t_moves			*best_way_AtoB(t_stack *A, t_stack *B, t_info *info);
void			free_move(t_moves *move);
int				common(t_moves *move);
int				maxval(t_stack *stack);
int				minval(t_stack *stack);
int				maxplace(t_stack *stack);
int				minplace(t_stack *stack);
int				rot_type(int len, int pos, char **rot);
int				find_moves(t_stack *stack, int len, int val, char **rot);
int				stack_pos(t_stack *stack, int val);
int				size_stack(t_stack *stack);
int				median(t_stack *stack, int size);
void			swap_A(t_stack *A, t_stack *B, t_info *info, int len);
int				is_sorted_first(t_stack *head, int dir, int size);
void			ft_add_move(t_info *info, char *move);
void			ft_operation_optimize(t_moves *head, t_moves *del, int f, int x);
void			ft_print_and_free(t_moves *src);
void			print_stacks(t_stack *A, t_stack *B);

#endif
