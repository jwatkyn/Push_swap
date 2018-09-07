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

int			*ft_checkinfo(char **tab, int count)
{
	int i;
	int j;

	i = -1;
	while (++i < count)
	{
		if (ft_longatoi(tab[i]) > MAX_INT)
			ERROR();
		j = -1;
		while (tab[i][++j])
			if (!(tab[i][j] >= '0' && tab[i][j] <= '9'))
				ERROR();
	}
	return (ft_intarray(tab, count));
}

void		ft_checkdup(int *val)
{
	int i;
	int j;

	i = -1;
	while (val[++i])
	{
		j = i;
		while (val[++j])
			if (val[i] == val[j])
				ERROR();
	}
}

int			*ft_intarray(char **tab, int count)
{
	int *values;
	int i;

	values = (int*)malloc(sizeof(int) * count - 1);
	i = -1;
	while (++i < count)
		values[i] = ft_atoi(tab[i]);
	ft_checkdup(values);
	return (values);
}

t_stack		*create_stacks(t_stack *A, int *values, int count)
{
	t_stack		*A_head;
	int			i;

	i = -1;
	A = create(values[++i]);
	A_head = A;
	while(++i < count)
		A_head = add_end(A_head, values[i]);
	i = -1;
	free(values);
	return (A_head);
}

t_stack		*ft_getinfo(char **tab, int count, t_stack *A)
{
	char	**val;
	int		*values;
	int		i;

	val = (char **)malloc(sizeof(char *) * count);
	i = 0;
	while (++i < count)
		val[i - 1] = ft_strdup(tab[i]);
	values = ft_checkinfo(val, count - 1);
	free_array(val);
	return (create_stacks(A, values, count -1));
}