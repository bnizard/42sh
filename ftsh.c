/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:34:46 by eseveno           #+#    #+#             */
/*   Updated: 2014/03/27 19:35:57 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <dirent.h>
#include <stdlib.h>
#include <ftsh.h>

char	**ft_sort(t_info *my, char ***env)
{
	if (my->type != 4)
		ft_exec_fork(my, *env);
	else
		*env = set_builtins(my, env);
	return (*env);
}

char	*ft_complete(char *env)
{
	char	*dest;
	int		i;

	i = -1;
	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(env + 1)))))
		return (NULL);
	while (env[++i])
		dest[i] = env[i];
	dest[i] = '\0';
	return (dest);
}

char	**ft_copyenv(t_info *my, char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	if (!(my->env = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = -1;
	while (env[++i])
		my->env[i] = ft_complete(env[i]);
	my->env[i] = NULL;
	return (my->env);
}

int		main(int argc, char **argv, char **env)
{
	t_info	my;
	int		a;

	a = 0;
	(void)argc;
	(void)argv;
	env = ft_copyenv(&my, env);
	while (1)
	{
		signal(SIGINT, ft_int);
		a = ft_read(&my, &env);
		if (a == 1)
			ft_freeall(&my);
		else if (a == 2)
		{
			ft_putendl(" exit");
			ft_exit(&my, &env);
		}
	}
	return (0);
}
