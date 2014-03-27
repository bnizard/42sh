/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:36:01 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 18:38:12 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

void	ft_freebuf(t_info *my)
{
	if (my->realbuf == NULL)
		return ;
	free(my->realbuf);
	my->realbuf = NULL;
}

void	ft_freearg(t_info *my)
{
	int	i;

	i = -1;
	if (my->arg == NULL)
		return ;
	while (my->arg[++i])
	{
		free(my->arg[i]);
		my->arg[i] = NULL;
	}
	free(my->arg);
	my->arg = NULL;
}

void	ft_freeway(t_info *my)
{
	int		i;

	i = -1;
	if (my->way == NULL)
		return ;
	while (my->way[++i])
	{
		free(my->way[i]);
		my->way[i] = NULL;
	}
	free(my->way);
	my->way = NULL;
}

void	ft_freeall(t_info *my)
{
	ft_freearg(my);
	ft_freeway(my);
	ft_freebuf(my);
}
