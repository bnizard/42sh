/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lexem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:09:48 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 10:58:17 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>

int			ft_check_lexem2(t_data **lexem, int i)
{
	if ((i > 0 && ((lexem[i]->type == 5 && lexem[i - 1]->type == 3)
			|| (lexem[i]->type == 5 && lexem[i - 1]->type == 5)))
			|| (i > 1 && lexem[i]->type == 5 && lexem[i - 1]->type == 6
			&& lexem[i - 2]->type == 5))
	{
		ft_putstr(lexem[i]->data);
		ft_putendl(" : No such file or directory");
		return (0);
	}
	else if ((i == 0 && lexem[i]->type == 6)
			|| (i > 1 && lexem[i]->type == 6 && lexem[i - 1]->type == 6
				&& lexem[i - 2]->type == 3))
	{
		ft_putstr("command not found : ");
		ft_putendl(lexem[i]->data);
		return (0);
	}
	return (1);
}

int			ft_check_lexem(t_data **lexem)
{
	int		i;

	i = 0;
	while (lexem[i] != NULL)
	{
		if (ft_check_lexem2(lexem, i) == 0)
			return (0);
		if (lexem[i]->type == -1 || (lexem[i]->type == 3
				&& (lexem[i + 1] != NULL && (lexem[i + 1]->type == 5
					|| lexem[i + 1]->type == 4))))
		{
			ft_putstr("parse error near ");
			ft_putendl(lexem[i]->data);
			return (0);
		}
		i++;
	}
	return (1);
}
