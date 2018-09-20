/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsC2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:41:29 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:41:31 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rb(t_stack *B, t_info *info)
{
	if (!info)
		return (NULL);
	B = add_end(B, B->content);
	B = del_begin(B);
	return (B);	
}

t_stack	*ft_ra(t_stack *A, t_info *info)
{
	if (!info)
		return (NULL);
	A = add_end(A, A->content);
	A = del_begin(A);
	return (A);
}

t_stack	*ft_rr(t_stack **A, t_stack *B, t_info *info)
{
	*A = ft_ra(*A, info);
	B = ft_rb(B, info);
	return (B);
}
