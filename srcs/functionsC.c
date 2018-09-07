/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsC.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:41:29 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:41:31 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_sa(t_stack *A)
{
	int		val;
	t_stack	*temp;

	if (!A)
		return (NULL);
	if (A->next)
	{
		val = A->content;
		temp = A->next;
		A->content = temp->content;
		temp->content = val;
	}
	return (A);
}

t_stack	*ft_sb(t_stack *B)
{
	int		val;
	t_stack	*temp;

	if (!B)
		return (NULL);
	if (B->next)
	{
		val = B->content;
		temp = B->next;
		B->content = temp->content;
		temp->content = val;
	}
	return (B);
}

t_stack	*ft_ss(t_stack **A, t_stack *B)
{
	*A = ft_sa(*A);
	B = ft_sb(B);
	return (B);
}

t_stack	*ft_pa(t_stack *A, t_stack **B)
{
	if (*B)
	{
		A = add_begin(A, (*B)->content);
		*B = del_begin(*B);
	}
	return (A);
}

t_stack	*ft_pb(t_stack *B, t_stack **A)
{
	if (*A)
	{
		B = add_begin(B, (*A)->content);
		*A = del_begin(*A);
	}
	return (B);
}

t_stack	*ft_ra(t_stack *A)
{
	A = add_end(A, A->content);
	A = del_begin(A);
	return (A);
}

t_stack	*ft_rb(t_stack *B)
{
	B = add_end(B, B->content);
	B = del_begin(B);
	return (B);	
}

t_stack	*ft_rr(t_stack **A, t_stack *B)
{
	*A = ft_ra(*A);
	B = ft_rb(B);
	return (B);
}

t_stack	*ft_rra(t_stack *A)
{
	int		val;
	t_stack	*temp;

	temp = A;
	while (temp->next)
		temp = temp->next;
	val = temp->content;
	A = add_begin(A, val);
	A = del_end(A);
	return (A);
}

t_stack	*ft_rrb(t_stack *B)
{
	int		val;
	t_stack	*temp;

	temp = B;
	while (temp->next)
		temp = temp->next;
	val = temp->content;
	B = add_begin(B, val);
	B = del_end(B);
	return (B);
}

t_stack	*ft_rrr(t_stack **A, t_stack *B)
{
	*A = ft_rra(*A);
	B = ft_rrb(B);
	return (B);
}
