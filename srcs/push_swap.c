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
	char	**tab;

	stack_a = (t_list *)malloc(sizeof(*stack_a));
	stack_b = (t_list *)malloc(sizeof(*stack_b));
	steps = (t_list *)malloc(sizeof(*steps));
	if (argc == 1)
	{
		ERROR;
		exit(1);
	}
	if (argc > 1)
	{
		info = (t_ps *)malloc(sizeof(*info));
		if (argc == 2)
		{
			tab = ft_strsplit((char*)argv[1], ' ');
			info->count = ft_countwords(argv[1], ' ');
		}
		else
			tab = argv + 1;
		info->A = *stack_a;
		info->B = *stack_b;
		info->steps = *steps;
		ft_checkinfo(info, tab, argc - 1);
		info->raw = tab;
		ft_getinfo(tab, info);
		ft_lstprint_all_int(&info->A);
		// if (info->flag < 8)
		// 	bruteforce(info);
		// else
		// 	ft_sort(info);
		free(info);
	}
	exit (0);
}
