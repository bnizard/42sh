/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <bdismuke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 20:40:07 by bdismuke          #+#    #+#             */
/*   Updated: 2014/03/27 19:21:39 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

char	**add_to_env(char **ft_env, char *path)
{
	int		i;
	char	**env_cpy;

	i = 0;
	while (ft_env != NULL && ft_env[i])
		i++;
	env_cpy = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (ft_env != NULL && ft_env[i])
	{
		env_cpy[i] = (char *)malloc(sizeof(char) * (ft_strlen(ft_env[i]) + 1));
		env_cpy[i] = ft_strcpy(env_cpy[i], ft_env[i]);
		free(ft_env[i]);
		i++;
	}
	if (path != NULL)
	{
		env_cpy[i] = (char *)malloc(sizeof(char) * (ft_strlen(path) + 1));
		env_cpy[i] = ft_strcpy(env_cpy[i], path);
	}
	env_cpy[i + 1] = NULL;
	free(ft_env);
	return (env_cpy);
}

char	**cpy_env(char **ft_env)
{
	int		i;
	char	**cpy_env;

	i = 0;
	if (ft_env == NULL)
		return (NULL);
	while (ft_env[i])
		i++;
	cpy_env = (char**)malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (ft_env[i])
	{
		cpy_env[i] = (char*)malloc(sizeof(char) * (ft_strlen(ft_env[i]) + 1));
		ft_strcpy(cpy_env[i], ft_env[i]);
		i++;
	}
	cpy_env[i] = NULL;
	return (cpy_env);
}
