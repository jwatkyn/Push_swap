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
