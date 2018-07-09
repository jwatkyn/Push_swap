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
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*steps;
	t_ps	*info;

	if (argc > 1)
	{
		info = (*info)malloc(sizeof(info))
		info->A = stack_a;
		info->B = stack_b;
		ft_checkinfo((char**)argv[1], argc - 1);
		ft_getinfo((char**)argv[1], argc - 1, info);
		if (info->flag < 8)
			bruteforce(info);
		else
			ft_sort(info);
		free(info)
	}
	exit (0);
}
