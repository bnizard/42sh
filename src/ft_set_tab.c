/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:10:26 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/26 19:56:06 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

static int		ft_set_tab2(t_tab **tab, t_stuff *st)
{
	ft_set_data(tab, st);
	if (st->lexem[st->i] != NULL
		&& (st->lexem[st->i]->type == 5 || st->lexem[st->i]->type == 4))
		ft_cpy_data(tab, st);
	while (st->lexem[st->i] != NULL && st->lexem[st->i]->type == 6)
	{
		ft_cpy_data(tab, st);
		if (st->lexem[st->i] != NULL
				&& (st->lexem[st->i]->type == 5 || st->lexem[st->i]->type == 4))
		{
			ft_cpy_data(tab, st);
			while (st->lexem[st->i] != NULL && st->lexem[st->i]->type == 6)
				ft_cpy_data(tab, st);
			return (0);
		}
	}
	return (1);
}

static void		ft_set_tab3(t_tab **tab, t_stuff *st)
{
	ft_set_data(tab, st);
	while (st->lexem[st->i] != NULL && st->lexem[st->i]->type == 6)
		ft_cpy_data(tab, st);
}

t_tab			**ft_set_tab(t_stuff *st)
{
	t_tab	**tab;

	st->i = 0;
	st->j = 0;
	st->n = 0;
	tab = (t_tab **)malloc(sizeof(t_tab *) * st->l);
	while (st->lexem[st->i] != NULL)
	{
		if (ft_strcmp(st->lexem[st->i]->data, "env") == 0)
			ft_set_tab2(tab, st);
		else if (st->lexem[st->i]->type == 5 || st->lexem[st->i]->type == 4)
			ft_set_tab3(tab, st);
		else
			ft_set_data(tab, st);
		if (tab[st->j]->data != NULL)
			tab[st->j]->data[st->n] = NULL;
		st->n = 0;
		st->j++;
	}
	tab[st->j] = NULL;
	return (tab);
}
