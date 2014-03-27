/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:11:42 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 12:28:28 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

static void			ft_set_isalnum_arg(char *arg, t_stuff *st)
{
	while ((ft_isalnum(arg[st->j]) || ft_is_other(arg[st->j])
			|| (st->j > 0 && arg[st->j - 1] == '\\'))
			&& arg[st->j] != '\0')
		st->j++;
	ft_put_node(st, arg);
	if (arg[st->j] == '-')
	{
		st->j++;
		while (ft_isalnum(arg[st->j]) && arg[st->j] != '\0')
			st->j++;
	}
	ft_put_node(st, arg);
}

static void			ft_sch_quotes(char *arg, t_stuff *st)
{
	char	*c;
	char	*d;
	int		flag;

	flag = 0;
	c = NULL;
	d = NULL;
	while (arg[st->j] != '\0' && (ft_strcmp(c, st->m) != 0
				|| ft_strcmp(d, st->m) == 0))
	{
		if (flag > 0)
			st->j++;
		free(d);
		d = NULL;
		free(c);
		c = NULL;
		c = ft_quote(arg[st->j]);
		if (arg[st->j + 1] != '\0')
			d = ft_quote(arg[st->j + 1]);
		flag = 1;
	}
}

static int			ft_set_quotes(char *arg, t_stuff *st)
{
	if ((st->m = ft_quote(arg[st->j])) != NULL)
	{
		st->j++;
		st->k++;
		ft_sch_quotes(arg, st);
		free(st->m);
		if (arg[st->j] == '\0')
		{
			ft_putendl("Unmatched symbol");
			return (0);
		}
		ft_put_node(st, arg);
		st->j++;
		st->k++;
	}
	return (1);
}

static void			ft_set_op(char *arg, t_stuff *st)
{
	char			*c;

	c = NULL;
	while (ft_op(arg[st->j]) != -1 && arg[st->j] != '\0')
		st->j++;
	ft_put_node(st, arg);
	while (ft_isalnum(arg[st->j]) == 0
			&& ft_op(arg[st->j]) == -1
			&& ft_is_other(arg[st->j]) == 0
			&& (c = ft_quote(arg[st->j])) == NULL
			&& arg[st->j] != '\0'
			&& arg[st->j] != '-')
		st->j++;
	free(c);
	c = NULL;
	st->k = st->j;
}

int					ft_set_lexem(char *arg, t_stuff *st)
{
	while (arg[st->k] != '\0')
	{
		ft_set_isalnum_arg(arg, st);
		if (ft_set_quotes(arg, st) == 0)
			return (0);
		ft_set_op(arg, st);
	}
	st->lexem[st->l] = NULL;
	return (1);
}
