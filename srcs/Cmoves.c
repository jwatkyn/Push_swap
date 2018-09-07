/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cmoves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:41:29 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:41:31 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack		*moves(t_stack *A, t_stack **B, char *line)
{
		if (!ft_strcmp(line, "pb"))
			*B = ft_pb(*B, &A);
		else if (!ft_strcmp(line, "rr"))
			*B = ft_rr(&A, *B);
		else if (!ft_strcmp(line, "pa"))
			A = ft_pa(A, &*B);
		else if (!ft_strcmp(line, "rra"))
			A = ft_rra(A);
		else if (!ft_strcmp(line, "rrb"))
			*B = ft_rrb(*B);
		else if (!ft_strcmp(line, "rrr"))
			*B = ft_rrr(&A, *B);
		else
			ft_putendl("Please enter a valid command");
		return (A);
}

t_stack		*complete_moves(t_stack *A, t_stack *B)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (!ft_strcmp(line, "sa"))
			A = ft_sa(A);
		else if (!ft_strcmp(line, "sb"))
			B = ft_sb(B);
		else if (!ft_strcmp(line, "ss"))
			B = ft_ss(&A, B);
		else if (!ft_strcmp(line, "ra"))
			A = ft_ra(A);
		else if (!ft_strcmp(line, "rb"))
			B = ft_rb(B);
		else
			A = moves(A, &B, line);
		free(line);
	}
	return (A);
}