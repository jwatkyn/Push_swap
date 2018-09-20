/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:55:04 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/09 14:03:06 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		maxval(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	temp = stack;
	i = MIN;
	while (temp)
	{
		if (temp->content > i)
			i = temp->content;
		temp = temp->next;
	}
	return (i);
}

int		minval(t_stack *stack)
{
	t_stack	*temp;
	int		i;

	temp = stack;
	i = MAX;
	while (temp)
	{
		if (temp->content < i)
			i = temp->content;
		temp = temp->next;
	}
	return (i);
}

int		maxplace(t_stack *stack)
{
	t_stack	*temp;
	int		i;
	int		place;
	int		len;

	temp = stack;
	i = MIN;
	len = 0;
	while (temp)
	{
		if (temp->content > i)
		{
			place = len;
			i = temp->content;
		}
		len++;
		temp = temp->next;
	}
	return (place);
}

int		minplace(t_stack *stack)
{
	t_stack	*temp;
	int		i;
	int		place;
	int		len;

	temp = stack;
	i = MAX;
	len = 0;
	while (temp)
	{
		if (temp->content < i)
		{
			place = len;
			i = temp->content;
		}
		len++;
		temp = temp->next;
	}
	return (place);
}

int		stack_pos(t_stack *stack, int val)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stack;
	while (temp)
	{
		i++;
		if (temp->content == val)
			break ;
		temp = temp->next;
	}
	return (i);
}
