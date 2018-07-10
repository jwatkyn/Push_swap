/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:55:04 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/09 14:03:06 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_countwords(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		while (*s == c)
			s++;
		count++;
	}
	return (count);
}

void	ft_checkinfo(t_ps *info, char **tab, int count)
{
	int i;

	if (count != 1)
		info->count = count;
	count = -1;
	while (++count < info->count)
	{
		i = -1;
		while (tab[count][++i] != '\0')
			if (!ft_isdigit(tab[count][i]))
			{
				ERROR;
				exit (1);
			}
	}
	ft_putendl("Check done");
}

void	ft_lstaddend(void *content, size_t content_size, t_list **begin)
{
	t_list *lst;
	t_list *temp;

	temp = *begin;
	lst = ft_lstnew(content, content_size);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = lst;
}

void	ft_getinfo(char** tab, t_ps *info)
{
	int		i;
	int		count;
	t_list	*lst;

	count = 0;
	i = ft_atoi(tab[0]);
	lst = ft_lstnew(&i, sizeof(int));
	while (++count < info->count)
	{
		i = ft_atoi(tab[count]);
		ft_lstaddend(&i, sizeof(int), &lst);
	}
	count = -1;
	ft_putendl("Obtained done");
}