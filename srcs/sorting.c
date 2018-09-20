/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:55:04 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/09 14:03:06 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*get_minmax(t_info *info, t_stack *A)
{
	int		count;
	int		min_count;
	int		alt;
	t_stack	*current;

	info->min = MAX;
	info->max = MIN;
	count = 1;
	min_count = 1;
	current = A;
	while (current != NULL)
	{
		info->min > current->content ? min_count = count : 0;
		info->min > current->content ? info->min = current->content : 0;
		info->max < current->content ? info->max = current->content : 0;
		current = current->next;
		count++;
	}
	info->min_count = min_count;
	alt = ABS((count - min_count + 1));
	min_count > (count / 2) ? info->min_count = alt : 0;
	info->dir = min_count > count / 2 ? 1 : -1;
	return (info);
}

t_stack	*sort(t_stack *A, t_stack *B, t_info *info)
{
	while (!is_sorted(A, 1) || B == NULL)
	{
		info = (get_minmax(info, A));
		if (info->min == A->next->content)
			A = ft_sa(A, info);
		else
			while (info->min_count-- -1 > 0)
				A = (info->dir == -1 ? ft_ra(A, info) : ft_rra(A, info));
		if (is_sorted(A, 1) && B == NULL)
			break ;
		if (B != NULL && is_sorted(A, 1) && is_sorted(B, 0))
			break ;
		B = ft_pb(B, &A, &info);
	}
	while (B != NULL)
		A = ft_pa(A, &B, &info);
	free(info);
	return (A);
}

t_stack	*quicksort(t_stack *A, t_stack *B, t_info *info)
{
	t_stack	*temp;

	while (!is_sorted(A, 1))
	{
		if (A->content > A->next->content)
			A = ft_sa(A, info);
		temp = A->next;
		if (!is_sorted(A, 1))
		{
			if (temp->content > temp->next->content)
				A = ft_rra(A, info);
			else
				A = ft_ra(B, info);
		}
	}
	return (A);
}