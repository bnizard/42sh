/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:39:42 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 12:24:44 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>

int				ft_op(char c)
{
	int			i;
	static char	op[2] =

	{'<', '>'};
	i = 0;
	while (i < 2)
	{
		if (c == op[i])
			return (i);
		i++;
	}
	return (-1);
}

char			*ft_is_builtin(char *str)
{
	int			i;
	static char	*buildin[6] =

	{"unsetenv", "setenv", "env", "echo", "exit", "cd"};
	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(str, buildin[i]) == 0)
			return (buildin[i]);
		i++;
	}
	return (NULL);
}

int				ft_is_other(char c)
{
	int			i;
	static char	other[9] =

	{'/', '\\', '$', '~', '.', '_', '-', '=', ':'};
	i = 0;
	while (i < 9)
	{
		if (c == other[i])
			return (1);
		i++;
	}
	return (0);
}
