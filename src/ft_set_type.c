/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:10:08 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 11:11:35 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

static void		ft_set_type3(t_data **lexem, int i, char *tmp)
{
	free(lexem[i]->data);
	lexem[i]->data = malloc(sizeof(char) * ft_strlen(tmp) + 1);
	lexem[i]->data = ft_strcpy(lexem[i]->data, tmp);
	if (ft_is_builtin(lexem[i]->data) != NULL)
		lexem[i]->type = 4;
	else
	{
		free(tmp);
		lexem[i]->type = 5;
	}
}

static int		ft_set_type2(t_data **lexem, int i)
{
	int			tmp;

	tmp = -1;
	if ((tmp = ft_is_op(lexem[i]->data)) != -1)
	{
		lexem[i]->type = tmp;
		return (1);
	}
	return (0);
}

t_data			**ft_set_type(t_data **lexem, char **env)
{
	int			i;
	char		*tmp;
	int			flag;

	i = 0;
	flag = 0;
	while (lexem[i] != NULL)
	{
		if (ft_set_type2(lexem, i) == 1)
			flag = 0;
		if ((i == 0 || (i > 0 && (flag != 1)))
			&& ((tmp = ft_is_builtin(lexem[i]->data)) != NULL
				|| (tmp = ft_is_cmd(lexem[i]->data, env)) != NULL))
		{
			flag = 1;
			ft_set_type3(lexem, i, tmp);
		}
		else if ((ft_isalnum(lexem[i]->data[0]) || ft_is_arg(lexem[i]->data)
				|| ft_quote(lexem[i]->data[0]) != NULL
				|| lexem[i]->data[0] == ' '
				|| ft_is_other(lexem[i]->data[0])) && lexem[i]->type == -1)
			lexem[i]->type = 6;
		i++;
	}
	return (lexem);
}
