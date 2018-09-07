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
# endif

typedef struct		s_info
{
	int				min_count;
	int				dir;
	int				max;
	int				min;
}					t_info;

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
t_stack			*sort(t_stack *A, t_stack *B);
t_stack			*ft_sa(t_stack *A);
t_stack			*ft_sb(t_stack *B);
t_stack			*ft_ss(t_stack **A, t_stack *B);
t_stack			*ft_pa(t_stack *A, t_stack **B);
t_stack			*ft_pb(t_stack *B, t_stack **A);
t_stack			*ft_ra(t_stack *A);
t_stack			*ft_rb(t_stack *B);
t_stack			*ft_rr(t_stack **A, t_stack *B);
t_stack			*ft_rra(t_stack *A);
t_stack			*ft_rrb(t_stack *B);
t_stack			*ft_rrr(t_stack **A, t_stack *B);
t_stack			*quicksort(t_stack *A, t_stack *B);
void			free_array(char **array);
void			free_list(t_stack *A);

#endif
