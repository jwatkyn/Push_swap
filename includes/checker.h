/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:42:28 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:43:44 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include "push_swap.h"

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

t_stack	*complete_moves(t_stack *A, t_stack *B, t_info *info);

#endif
