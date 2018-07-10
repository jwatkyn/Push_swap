/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwatkyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 08:43:53 by jwatkyn           #+#    #+#             */
/*   Updated: 2018/07/02 08:44:37 by jwatkyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR ft_putendl_fd("ERROR", 2);

# include "../libft/includes/libft.h"
# include "checker.h"
# include <stdio.h>

typedef struct	s_ps
{
	char	**raw;
	t_list	A;
	t_list	B;
	t_list	steps;
	int		flag;
	int		count;
}				t_ps;

void			ft_getinfo(char** tab, t_ps *info);
void			bruteforce(t_ps *info);
void			ft_sort(t_ps *info);
void			ft_checkinfo(t_ps *info, char **tab, int count);
int				ft_countwords(char const *s, char c);

#endif
