/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:41:29 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:41:31 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		A = (t_stack *)malloc(sizeof(t_stack));
		A = ft_getinfo(argv, argc, A);
		info = initialise(A);
		if (A->next == NULL)
			exit(0);
		A = complete_moves(A, B, info);
	}
	else
		ERROR();
	if (is_sorted(A, 1) && B == NULL)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	exit (0);
}
