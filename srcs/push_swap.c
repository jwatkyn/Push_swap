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

int		main(int argc, char **argv)
{
	t_stack	*A;
	t_stack *B;

	if (argc >= 2)
	{
		B = NULL;
		A = NULL;
		A = ft_getinfo(argv, argc, A);
		if (A->next == NULL)
			exit(0);
		if (is_sorted(A, 1))
			exit(0);
		if (argc < 5)
			A = quicksort(A, B);
		else
			A = sort(A, B);
	}
	else
		ERROR();
	free_list(A);
	exit (0);
}
