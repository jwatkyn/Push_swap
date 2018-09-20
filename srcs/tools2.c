/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:55:04 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/09 14:03:06 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_move(t_info *info, char *move)
{
	t_moves	*moves;
	t_moves	*temp;

	moves = (t_moves *)malloc(sizeof(t_moves));
	moves->move = ft_strdup(move);
	moves->next = NULL;
	temp = info->moves;
	if (info->moves == NULL)
		info->moves = moves;
	else
	{
		while (temp->next)
			temp =temp->next;
		temp->next = moves;
	}
}

void	ft_print_and_free(t_moves *src)
{
	t_moves *del;

	while (src)
	{
		del = src;
		ft_putendl(src->move);
		src = src->next;
		ft_strdel(&del->move);
		free(del);
	}
}

int		ft_optimization(t_moves *s, int f)
{
	if (s->next == NULL)
		return (0);
	(s->move[0] == 's' && s->next->move[0] == 's' && ((s->move[1] == 'a' &&
		s->next->move[1] == 'b') || 
		(s->move[1] == 'b' && s->next->move[1] == 'a'))) ? (f = 1) : 0;
	(s->move[0] == 'r' && s->next->move[0] == 'r' && ((s->move[1] == 'a' &&
		s->next->move[1] == 'b') || 
		(s->move[1] == 'b' && s->next->move[1] == 'a'))) ? (f = 2) : 0;
	(s->move[0] == 'r' && s->next->move[0] == 'r' && ((s->move[2] == 'a' &&
		s->next->move[2] == 'b') || 
		(s->move[2] == 'b' && s->next->move[2] == 'a'))) ? (f = 3) : 0;
	(s->move[0] == 'p' && s->next->move[0] == 'p' && ((s->move[1] == 'a' &&
		s->next->move[1] == 'b') || 
		(s->move[1] == 'b' && s->next->move[1] == 'a'))) ? (f = 4) : 0;
	(s->move[0] == 'r' && s->next->move[0] == 'r' && ((s->move[1] == 'a' &&
		s->next->move[1] == 'r' && s->next->move[2] == 'a') ||  (s->move[1] 
		== 'r' && s->move[2] == 'a' && s->next->move[1] == 'a'))) ? (f = 5) : 0;
	(s->move[0] == 'r' && s->next->move[0] == 'r' && ((s->move[1] == 'b' &&
		s->next->move[1] == 'r' && s->next->move[2] == 'b') || (s->move[1] == 
		'r' && s->move[2] == 'b' && s->next->move[1] == 'b'))) ? (f = 6) : 0;
	(f == 1 || f == 2 || f == 3) ? (ft_strdel(&(s->move))) : 0;
	(f == 1) ? (s->move = ft_strdup("ss")) : 0;
	(f == 2) ? (s->move = ft_strdup("rr")) : 0;
	(f == 3) ? (s->move = ft_strdup("rrr")) : 0;
	return (f);
}

void	ft_operation_optimize(t_moves *head, t_moves *del, int f, int x)
{
	t_moves	*point;

	while (f)
	{
		point = head;
		f = 0;
		del = point;
		while (point != NULL)
		{
			if ((x = ft_optimization(point, 0)) != 0)
			{
				f = 1;
				(x == 4 || x == 5 || x == 6) ? (del->next = point->next->next)
					: (del = point->next);
				(x == 4 || x == 5 || x == 6) ? (free(point->next->move)) :
					(point->next = point->next->next);
				(x == 4 || x == 5 || x == 6) ? (free(point->move)) : 
					(free(del));
				(x == 4 || x == 5 || x == 6) ? (free(point->next)) : 0;
				(x == 4 || x == 5 || x == 6) ? (free(point)) : 0;
				(x == 4 || x == 5 || x == 6) ? (point = del) : 0;
			}
			del = point;
			point = point->next;
		}
	}
}
