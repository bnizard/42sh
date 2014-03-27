/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:30:52 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 18:48:58 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <ftsh.h>

int		ft_strlen_2d(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_exit(t_info *my, char ***env)
{
	(void)my;
	(void)env;
	exit(0);
}

char	**set_builtins(t_info *my, char ***env)
{
	int					i;
	static t_builtins	builtins[] =

	{{"exit", (t_builts)(ft_exit)}, {"env", (t_builts)(ft_env)},
	{"unsetenv", (t_builts)(ft_unsetenv)}, {"setenv", (t_builts)(ft_setenv)},
	{"cd", (t_builts)(ft_cd)}, {"echo", (t_builts)(ft_echo)}, {NULL, NULL}};
	i = 0;
	while (builtins[i].name)
	{
		if (!ft_strcmp(builtins[i].name, my->arg[0]))
		{
			builtins[i].fnt(my, env);
			ft_freearg(my);
			ft_freebuf(my);
			ft_freeway(my);
			break ;
		}
		i++;
	}
	return (*env);
}

void	ft_exec_fork(t_info *my, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
		wait(0);
	if (pid == 0)
		execve(my->arg[0], my->arg, env);
}

void	ft_int(int c)
{
	c = 0x0D;
	write(0, &c, 1);
}
