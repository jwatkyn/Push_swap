/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:55:04 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/09 14:03:06 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_info *info, int size, int stack)
{
	if (!is_sorted_first((stack) ? info->A : info->B, stack, size))
	{
		if (!is_sorted_first((stack) ? info->A : info->B, stack, 2))
			(stack) ? (info->A = ft_sa(info->A, info)) : 
				(info->B = ft_sb(info->B, info));
		else
		{
			(stack) ? (info->A = ft_ra(info->A, info)) : 
				(info->B = ft_rb(info->B, info));
			(stack) ? (info->A = ft_sa(info->A, info)) : 
				(info->B = ft_sb(info->B, info));
			(stack) ? (info->A = ft_rra(info->A, info)) : 
				(info->B = ft_rrb(info->B, info));
		}
		sort2(info, size, stack);
	}
}

int		sort1(t_info *info, int stack, int med)
{
	if ((stack && info->A->content < med) || 
		(!stack && info->B->content >= med))
	{
		(stack) ? (info->B = ft_pb(info->B, &(info->A), &info)) : 
		(info->A = ft_pa(info->A, &(info->B), &info));
		return (1);
	}
	else
		(stack) ? (info->A = ft_ra(info->A, info)) : 
			(info->B = ft_rb(info->B, info));
	return (0);
}

void	repeat_sort(t_info *info, int size, int stack, int n)
{
	int		i;
	int		reset;
	int		med;

	i = 0;
	reset = 0;
	med = median((stack) ? info->A : info->B, size);
	if (is_sorted((stack) ? info->A : info->B, stack))
		return ;
	while (size > 3 && i < (size / 2) + (size % 2 && !stack) && ++reset)
		i += sort1(info, stack, med);
	while ((!n) && (reset--) - i)
		(stack) ? (info->A = ft_rra(info->A, info)) : 
			(info->B = ft_rrb(info->B, info));
	if (i && !stack)
		repeat_sort(info, i, !stack, 0);
	(size - i <= 3) ? sort2(info, size - i, stack) : 
		repeat_sort(info, size - i, stack, (n == 2) ? n - 1 : n);
	if (i && stack)
		repeat_sort(info, i, !stack, (n == 2) ? 1 : 0);
	while (i--)
		(stack) ? (info->A = ft_pa(info->A, &(info->B), &info)) : 
		(info->B = ft_pb(info->B, &(info->A), &info));
}

t_stack	*large_sort(t_stack *A, t_stack *B, t_info *info)
{
	t_moves	*point;

	point =  NULL;
	info->A = A;
	info->B = B;
	repeat_sort(info, info->sizeA, 1, 2);
	ft_operation_optimize(info->moves, point, 1, 0);
	return (A);
}
