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

t_stack	*ft_sa(t_stack *A, t_info *info)
{
	int		val;
	t_stack	*temp;

	if (!A || !info)
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

t_stack	*ft_sb(t_stack *B, t_info *info)
{
	int		val;
	t_stack	*temp;

	if (!B || !info)
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

t_stack	*ft_ss(t_stack **A, t_stack *B, t_info *info)
{
	*A = ft_sa(*A, info);
	B = ft_sb(B, info);
	return (B);
}
