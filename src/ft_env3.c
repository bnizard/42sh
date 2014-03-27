/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:27:30 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 19:34:14 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <dirent.h>
#include <stdlib.h>

void	ft_env2(t_info *my, char **ft_env, char *path, int i)
{
	char	*cmd;
	int		j;

	j = 0;
	if (!my->arg[i])
	{
		generate_env(ft_env);
		ft_free_env(ft_env);
	}
	else
	{
		ft_env = confirm_path(ft_env, path);
		if (ft_is_builtin(my->arg[i]) == NULL)
		{
			while (ft_env != NULL && ft_env[j] != NULL
					&& ft_strncmp("PATH=", ft_env[j], 5) != 0)
				j++;
			if ((cmd = ft_env3(ft_env, j, my->arg[i], path)) == NULL)
				return ;
			ft_env4(cmd, &(my->arg[i]), i, ft_env);
		}
		else
			ft_env5(my->arg, i, j, ft_env);
	}
}

void	ft_env(t_info *my, char ***env)
{
	int		i;
	char	**ft_env;
	char	*path;

	i = 1;
	path = NULL;
	ft_env = cpy_env(*env);
	if (my->envcpy)
		ft_free_env(*env);
	while (my->arg[i] != NULL && (ft_strcmp("-i\0", my->arg[i]) == 0 ||
				ft_strchr((const char *)my->arg[i], '=') != NULL))
	{
		if (i == 1 && ft_strcmp("-i\0", my->arg[1]) == 0)
		{
			path = ft_pathway(ft_env);
			ft_strdel(ft_env);
		}
		if (ft_strchr((const char *)my->arg[i], '=') != NULL)
			ft_env = modify_env(ft_env, my->arg[i]);
		i++;
	}
	ft_env2(my, ft_env, path, i);
}

char	*ft_set_path(DIR *directory, char **pathway, int i, char *table)
{
	char	*tmp;

	tmp = NULL;
	closedir(directory);
	tmp = pathway[i];
	pathway[i] = ft_strjoin(pathway[i], "/");
	free(tmp);
	tmp = NULL;
	tmp = pathway[i];
	tmp = ft_strjoin(pathway[i], table);
	ft_free_env(pathway);
	return (tmp);
}

char	*command_search(char *table, char *env)
{
	char			**pathway;
	DIR				*directory;
	struct dirent	*readable;
	int				i;

	i = 0;
	if (env == NULL)
		return (NULL);
	pathway = ft_strsplit(env + 5, ':');
	i = 0;
	while (pathway[i])
	{
		if ((directory = opendir((const char *)pathway[i])))
		{
			while ((readable = readdir(directory)))
			{
				if (!ft_strcmp(table, readable->d_name))
					return (ft_set_path(directory, pathway, i, table));
			}
		}
		if (directory != NULL)
			closedir(directory);
		i++;
	}
	return (NULL);
}
