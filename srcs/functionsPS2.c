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
