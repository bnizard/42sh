/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmellado <dmellado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 15:20:46 by dmellado          #+#    #+#             */
/*   Updated: 2014/03/26 19:55:11 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

char	backslash_char(char c)
{
	char	r;

	if (c == 'a')
		r = '\a';
	else if (c == 'b')
		r = '\b';
	else if (c == 'f')
		r = '\f';
	else if (c == 'n')
		r = '\n';
	else if (c == 'r')
		r = '\r';
	else if (c == 't')
		r = '\t';
	else if (c == 'v')
		r = '\v';
	else if (c == '\\')
		r = '\\';
	else
		r = c;
	return (r);
}

int		*init_int_tab(void)
{
	int		i;
	int		*arg;

	i = 0;
	if (!(arg = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	while (i < 4)
	{
		arg[i] = 0;
		i++;
	}
	return (arg);
}

int		*find_options(t_info *my)
{
	int		*tab;
	int		i;
	int		j;

	i = 0;
	tab = init_int_tab();
	while (ft_strncmp(my->arg[++i], "-", 1) == 0)
	{
		j = 0;
		while (my->arg[i][++j])
		{
			if (my->arg[i][j] == 'n')
				tab[1] = 1;
			else if (my->arg[i][j] == 'e')
				tab[2] = 1;
			else if (my->arg[i][j] == 'E')
				tab[3] = 1;
			else
				return (tab);
		}
		tab[0]++;
	}
	tab[0]++;
	return (tab);
}

int		execute_option(t_info *my, int *arg, int max, char ***env)
{
	while (arg[0] <= max)
	{
		if (arg[3] == 1)
			ft_putstr(my->arg[arg[0]]);
		else
			echo_putstr(my->arg[arg[0]], env);
		if (arg[0] < max)
			ft_putchar(' ');
		arg[0]++;
	}
	if (arg[1] == 0)
		ft_putchar('\n');
	return (0);
}

int		ft_echo(t_info *my, char ***env)
{
	int		max;
	int		*arg;

	max = ft_strlen_2d(my->arg) - 1;
	if (!max)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		arg = find_options(my);
		execute_option(my, arg, max, env);
		free(arg);
	}
	return (0);
}
