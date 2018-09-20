/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:41:39 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:41:40 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		median(t_stack *stack, int size)
{
	int		bigger;
	int		lower;
	int		i;
	t_stack	*cur;
	t_stack	*tmp;

	cur = stack;
	bigger = 0;
	lower = 2;
	while (bigger - lower != 0 && bigger - lower != -1)
	{
		bigger = 0;
		lower = 0;
		i = -1;
		tmp = stack;
		while (++i < size)
		{
			bigger += (cur->content < tmp->content);
			lower += (cur->content > tmp->content);
			tmp = tmp->next;
		}
		tmp = cur;
		cur = cur->next;
	}
	return (tmp->content);
}

int		size_stack(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

t_info	*initialise(t_stack *A)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->moves = NULL;
	info->sizeA = size_stack(A);
	info->sizeB = 0;
	return (info);
}

int		main(int argc, char **argv)
{
	t_stack	*A;
	t_stack *B;
	t_info	*info;

	if (argc >= 2)
	{
		B = NULL;
		A = NULL;
		A = ft_getinfo(argv, argc, A);
		info = initialise(A);
		if (A->next == NULL)
			exit(0);
		if (is_sorted(A, 1))
			exit(0);
		if (argc < 5)
			A = quicksort(A, B, info);
		else if (argc < 13)
			A = sort(A, B, info);
		else
			A = large_sort(A, B, info);
		ft_print_and_free(info->moves);
	}
	else
		ERROR();
	exit (0);
}
