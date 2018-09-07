/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:41:39 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:41:40 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*create(int val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->content = val;
	new->next = NULL;
	return (new);
}

t_stack		*add_end(t_stack *head, int val)
{
	t_stack	*new;
	t_stack	*temp;

	new = create(val);
	temp = head;
	if (head == NULL)
		head = new;
	else
		while (temp->next != NULL)
			temp = temp->next;
	temp->next = new;
	return (head);
}

t_stack		*add_begin(t_stack *head, int val)
{
	t_stack *new;

	new = create(val);
	new->next = head;
	return (new);
}

t_stack		*del_end(t_stack *head)
{
	t_stack *temp1;
	t_stack *temp2;

	if (!head)
		return (NULL);
	temp1 = head;
	temp2 = NULL;
	while(temp1->next != NULL)
	{
		temp2 = temp1;
		temp1 = temp1->next;
	}
	if (temp2)
		temp2->next = NULL;
	if (temp1 == head)
		head = NULL;
	free(temp1);
	return (head);
}

t_stack		*del_begin(t_stack *head)
{
	t_stack *temp;

	if (!head)
		return (NULL);
	if (!(head->next))
	{
		free(head);
		return (NULL);
	}
	temp = head;
	head = head->next;
	temp->next = NULL;
	free(temp);
	return (head);
}