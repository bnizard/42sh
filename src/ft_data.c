/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:42:50 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 10:58:35 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

static t_data		*ft_node(char *arg, int i, int j)
{
	t_data			*node;
	int				k;

	k = 0;
	node = (t_data *)malloc(sizeof(t_data));
	node->data = (char *)malloc(sizeof(char) * (i - j + 1));
	while (j < i)
		node->data[k++] = arg[j++];
	node->type = -1;
	node->data[k] = '\0';
	return (node);
}

void				ft_put_node(t_stuff *st, char *arg)
{
	if (st->j != st->k)
	{
		st->lexem[st->l] = ft_node(arg, st->j, st->k);
		st->l++;
		st->lexem[st->l] = NULL;
	}
	st->k = st->j;
}

void				ft_cpy_data(t_tab **tab, t_stuff *st)
{
	tab[st->j]->data[st->n] = (char *)malloc(sizeof(char) * \
			ft_strlen(st->lexem[st->i]->data) + 1);
	tab[st->j]->data[st->n] = ft_strcpy(tab[st->j]->data[st->n], \
			st->lexem[st->i]->data);
	st->i++;
	st->n++;
	tab[st->j]->data[st->n] = NULL;
}

void				ft_set_data(t_tab **tab, t_stuff *st)
{
	tab[st->j] = (t_tab *)malloc(sizeof(t_tab) * (st->l + 1));
	tab[st->j]->type = st->lexem[st->i]->type;
	tab[st->j]->data = (char **)malloc(sizeof(char *) * (st->l + 1));
	tab[st->j]->data[st->n] = (char *)malloc(sizeof(char) * \
			ft_strlen(st->lexem[st->i]->data) + 1);
	tab[st->j]->data[st->n] = ft_strcpy(tab[st->j]->data[st->n], \
			st->lexem[st->i]->data);
	st->n++;
	st->i++;
	tab[st->j]->data[st->n] = NULL;
}
