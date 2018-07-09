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

# include "libft.h"
# include "checker.h"

define struct	s_ps
{
	t_list	A;
	t_list	B;
	int		flag;

}				t_ps;

void			ft_getinfo(char** info, int argc, t_ps *info);
void			ft_checkinfo(char** info, int argc);
void			bruteforce(t_ps info);
void			ft_sort(t_ps info);

#endif
