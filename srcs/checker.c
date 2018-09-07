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

int		main(int argc, char **argv)
{
	t_stack	*A;
	t_stack *B;

	if (argc >= 2)
	{
		B = NULL;
		A = (t_stack *)malloc(sizeof(t_stack));
		A = ft_getinfo(argv, argc, A);
		if (A->next == NULL)
			exit(0);
		A = complete_moves(A, B);
	}
	else
		ERROR();
	if (is_sorted(A, 1) && B == NULL)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	exit (0);
}
