/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsPS2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:41:29 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:41:31 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_pa(t_stack *A, t_stack **B)
{
	ft_putendl("pa");
	if (*B)
	{
		A = add_begin(A, (*B)->content);
		*B = del_begin(*B);
	}
	return (A);
}

t_stack	*ft_pb(t_stack *B, t_stack **A)
{
	ft_putendl("pb");
	if (*A)
	{
		B = add_begin(B, (*A)->content);
		*A = del_begin(*A);
	}
	return (B);
}

t_stack	*ft_ra(t_stack *A)
{
	ft_putendl("ra");
	A = add_end(A, A->content);
	A = del_begin(A);
	return (A);
}

t_stack	*ft_rb(t_stack *B)
{
	ft_putendl("rb");
	B = add_end(B, B->content);
	B = del_begin(B);
	return (B);	
}

t_stack	*ft_rr(t_stack **A, t_stack *B)
{
	ft_putendl("rr");
	*A = add_end(*A, (*A)->content);
	*A = del_begin(*A);
	B = add_end(B, B->content);
	B = del_begin(B);
	return (B);
}
