/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsPS.c                                      :+:      :+:    :+:   */
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

	ft_putendl("sa");
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


	ft_putendl("sb");
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
	int		val;
	t_stack	*temp;

	ft_putendl("ss");
	if (!*A && (*A)->next)
	{
		val = (*A)->content;
		temp = (*A)->next;
		(*A)->content = temp->content;
		temp->content = val;
	}
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

t_stack	*ft_rra(t_stack *A)
{
	int		val;
	t_stack	*temp;

	ft_putendl("rra");
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

	ft_putendl("rrb");
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
	int		val;
	t_stack	*temp;

	ft_putendl("rrr");
	temp = *A;
	while (temp->next)
		temp = temp->next;
	val = temp->content;
	*A = add_begin(*A, val);
	*A = del_end(*A);
	temp = B;
	while (temp->next)
		temp = temp->next;
	val = temp->content;
	B = add_begin(B, val);
	B = del_end(B);
	return (B);
}
