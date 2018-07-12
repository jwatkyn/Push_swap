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

#include "push_swap.h"

void	ft_sa(t_ps *info)
{
	int		temp;

	if (info->sizea > 1)
	{
		temp = A->content;
		info->A->content = info->A->next->content;
		info->A->next->content = temp;
	}
}

void	ft_sb(t_ps *info)
{
	int		temp;

	if (info->sizeb > 1)
	{
		temp = B->content;
		info->B->content = info->B->next->content;
		info->B->next->content = temp;
	}
}

void	ft_ss(t_ps *info)
{
	ft_sa(info);
	ft_sb(info);
}

void	ft_pa(t_ps *info)
{
	int		temp;

	if (info->sizea > 0)
	{
		if (info->sizea == 1)
		{
			
		}
	}
}

void	ft_pb(t_ps *info)
{

}

void	ft_ra(t_ps *info)
{

}

void	ft_rb(t_ps *info)
{
	
}

void	ft_rr(t_ps *info)
{
	
}

void	ft_rra(t_ps *info)
{
	
}

void	ft_rrb(t_ps *info)
{
	
}

void	ft_rrr(t_ps *info)
{
	
}
