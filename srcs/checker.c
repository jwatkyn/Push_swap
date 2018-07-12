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

#include "checker.h"
#include "../libft/includes/libft.h"

int		main(int argc, char **argv)
{
	char	**tab;
	int		i;

	i = 0;
	if (argc > 1)
	{
		if (argc == 1)
			tab = ft_strsplit(argv[1], ' ');
		else
			tab = (char**)argv[1];
	}
	while (tab[i])
	{
		i++;
	}
	exit (0);
}
