/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:05:06 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/26 19:56:42 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <ftsh.h>

static char	**ft_path(char **env)
{
	char	**path;
	int		i;
	char	*tmp;

	i = 0;
	while (env != NULL && env[i] != NULL && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (env[i] == NULL)
		return (NULL);
	path = ft_strsplit(env[i], ':');
	tmp = (char *)malloc(sizeof(char) * ft_strlen(path[0]) + 1);
	tmp = ft_strcpy(tmp, ft_strchr(path[0], '='));
	free(path[0]);
	path[0] = tmp;
	return (path);
}

static void	ft_free_path(char **path, char *str)
{
	int		i;

	i = 0;
	while (path[i] != NULL)
	{
		free(path[i]);
		path[i++] = NULL;
	}
	free(str);
	str = NULL;
	free(path);
	path = NULL;
}

char		*ft_find_path(char *str, char **env)
{
	char	**path;
	char	*all_path;
	int		i;

	i = 0;
	str = ft_strjoin("/", str);
	if ((path = ft_path(env)) == NULL)
		return (NULL);
	all_path = ft_strjoin(path[i], str);
	while (path[i] != NULL && access(all_path, X_OK) != 0)
	{
		i++;
		free(all_path);
		all_path = NULL;
		if (path[i] != NULL)
			all_path = ft_strjoin(path[i], str);
	}
	if (path[i] == NULL)
	{
		ft_free_path(path, str);
		return (NULL);
	}
	ft_free_path(path, str);
	return (all_path);
}
