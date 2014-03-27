/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:52:24 by bnizard           #+#    #+#             */
/*   Updated: 2014/03/26 19:56:18 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

char	*ft_setenvchange(t_info *my, int k)
{
	char	*tmp;

	tmp = my->arg[1];
	if (!k)
		tmp = ft_strjoin(my->arg[1], my->arg[2]);
	else
		tmp = ft_strjoin(tmp, "");
	return (tmp);
}

char	*ft_setenvcrea(char *env)
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

char	**ft_setenvcreate(char ***env, t_info *my, int k)
{
	char	**newenv;
	int		i;

	i = 0;
	while ((*env)[i])
		i++;
	if (!(newenv = (char**)malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	while ((*env)[i])
	{
		newenv[i] = ft_setenvcrea((*env)[i]);
		free((*env)[i]);
		(*env)[i++] = NULL;
	}
	free(*env);
	*env = NULL;
	newenv[i] = ft_setenvchange(my, k);
	newenv[i + 1] = NULL;
	return (newenv);
}

char	**ft_setenvupdate(t_info *my, int k, char ***env)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	tmp = my->arg[1];
	my->arg[1] = ft_strjoin(my->arg[1], "=");
	free(tmp);
	tmp = NULL;
	len = ft_strlen(my->arg[1]);
	while ((*env)[i] && (ft_strncmp((*env)[i], my->arg[1], len)))
		i++;
	if ((*env)[i])
	{
		free((*env)[i]);
		(*env)[i] = NULL;
		(*env)[i] = ft_setenvchange(my, k);
	}
	else
		*env = ft_setenvcreate(env, my, k);
	i = 0;
	return (*env);
}

char	**ft_setenv(t_info *my, char ***env)
{
	int	i;
	int	arg;

	i = 0;
	arg = ft_strlen_2d(my->arg);
	arg--;
	if (arg < 3)
	{
		if (arg == 2)
			ft_setenvupdate(my, 0, env);
		else if (arg == 1)
			ft_setenvupdate(my, 1, env);
		else
		{
			while ((*env)[i])
				ft_putendl((*env)[i++]);
		}
	}
	else
		ft_putendl("setenv: Too many arguments");
	return (*env);
}
