/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:27:20 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 19:32:53 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_pathway(char **ft_env)
{
	int		i;

	i = 0;
	while (ft_env != NULL && ft_env[i] != NULL
			&& ft_strncmp("PATH=", ft_env[i], 5) != 0)
		i++;
	if (ft_env != NULL && ft_env[i] != NULL
			&& ft_strncmp("PATH=", ft_env[i], 5) == 0)
	{
		return (ft_coppath(ft_env[i], 5));
	}
	return (NULL);
}

void	ft_strdel(char **as)
{
	if (&(*as) == NULL)
		return ;
	free(*as);
	*as = NULL;
}

void	ft_env5(char **arg, int i, int j, char **ft_env)
{
	t_info	*new_my;

	new_my = NULL;
	if (arg[i] != NULL)
	{
		new_my = ft_init_info();
		new_my->arg = (char **)malloc(sizeof(char *) \
				* (ft_ptrlen(arg) - i + 1));
		while (arg[i] != NULL)
		{
			new_my->arg[j] = (char *)malloc(sizeof(char) * \
					(ft_strlen(arg[i]) + 1));
			new_my->arg[j] = ft_strcpy(new_my->arg[j], arg[i]);
			j++;
			i++;
		}
		new_my->arg[j] = NULL;
		new_my->envcpy = 1;
		set_builtins(new_my, &ft_env);
	}
}

void	ft_env4(char *cmd, char **arg, int i, char **ft_env)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
	{
		wait(0);
		free(cmd);
	}
	if (pid == 0)
	{
		if (execve(cmd, arg, ft_env) == -1)
			ft_env_error(arg[i]);
		exit(0);
	}
}

char	*ft_env3(char **ft_env, int j, char *arg, char *path)
{
	char	*cmd;

	cmd = NULL;
	if (ft_env[j] != NULL)
	{
		if (!(cmd = command_search(arg, ft_env[j])))
		{
			ft_env_file_error(arg);
			ft_free_env(ft_env);
			return (NULL);
		}
	}
	else
	{
		if (!(cmd = command_search(arg, path)))
		{
			ft_env_file_error(arg);
			free(path);
			return (NULL);
		}
	}
	return (cmd);
}
