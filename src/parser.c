/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 17:31:18 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/26 19:56:35 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

static void		ft_free_stuff(t_stuff *st)
{
	int			i;

	i = 0;
	while (st->lexem[i] != NULL && st->lexem[i]->data != NULL)
	{
		free(st->lexem[i]->data);
		st->lexem[i]->data = NULL;
		free(st->lexem[i]);
		st->lexem[i] = NULL;
		i++;
	}
	free(st->lexem);
	st->lexem = NULL;
	free(st);
	st = NULL;
}

static t_stuff	*ft_init_stuff(char *arg)
{
	t_stuff		*st;

	st = (t_stuff *)malloc(sizeof(t_stuff));
	st->l = 0;
	st->k = 0;
	st->j = 0;
	st->i = 0;
	st->lexem = (t_data **)malloc(sizeof(t_data *) * (ft_strlen(arg) + 1));
	st->m = NULL;
	return (st);
}

t_tab			**ft_parser(char *arg, char **env)
{
	t_tab		**tab;
	t_stuff		*st;

	st = ft_init_stuff(arg);
	if (ft_set_lexem(arg, st) == 0)
	{
		ft_free_stuff(st);
		return (NULL);
	}
	st->lexem = ft_set_type(st->lexem, env);
	if (st->lexem[0] == NULL)
	{
		ft_free_stuff(st);
		return (NULL);
	}
	if (ft_check_lexem(st->lexem) == 0)
	{
		ft_free_stuff(st);
		return (NULL);
	}
	tab = ft_set_tab(st);
	ft_free_stuff(st);
	return (tab);
}
