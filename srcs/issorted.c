/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:55:04 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/09 14:03:06 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted2(t_stack *head)
{
	t_stack	*temp;

	while (head->next)
	{
		temp = head->next;
		if (head->content < temp->content)
			return (0);
		head = head->next;
	}
	return (1);
}

int		is_sorted(t_stack *head, int dir)
{
	t_stack	*temp;

	if (dir)
	{
		while (head->next)
		{
			temp = head->next;
			if (head->content > temp->content)
				return (0);
			head = head->next;
		}
	}
	else
		return (is_sorted2(head));
	return (1);
}

int		is_sorted_first2(t_stack *head, int size)
{
	t_stack	*temp;
	int		i;

	i = 0;
	while (head->next && ++i < size)
	{
		temp = head->next;
		if (head->content < temp->content)
			return (0);
		head = head->next;
	}
	return (1);
}

int		is_sorted_first(t_stack *head, int dir, int size)
{
	t_stack	*temp;
	int		i;

	i = 0;
	if (dir)
	{
		while (head->next && ++i < size)
		{
			temp = head->next;
			if (head->content > temp->content)
				return (0);
			head = head->next;
		}
	}
	else
		return (is_sorted_first2(head, size));
	return (1);
}