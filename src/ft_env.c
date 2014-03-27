/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <bdismuke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 15:49:10 by bdismuke          #+#    #+#             */
/*   Updated: 2014/03/27 19:33:27 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <ftsh.h>

void	ft_free_env(char **ft_env)
{
	int		i;

	i = 0;
	if (ft_env == NULL)
		return ;
	while (ft_env[i])
	{
		free(ft_env[i]);
		ft_env[i] = NULL;
		i++;
	}
	free(ft_env);
	ft_env = NULL;
}

void	generate_env(char **ft_env)
{
	int	i;

	i = 0;
	while (ft_env[i])
	{
		ft_putstr(ft_env[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_strlen_chr(char *line, int c)
{
	int		count;

	count = 0;
	while (line != NULL && line[count] != c && line[count] != '\0')
		count++;
	if (line != NULL && line[count] == c)
		return (count + 1);
	return (0);
}

char	**confirm_path(char **ft_env, char *path)
{
	int		i;

	i = 0;
	while (path != NULL && ft_env != NULL && ft_env[i])
	{
		if (ft_strncmp(ft_env[i], path, 5))
			return (ft_env);
		i++;
	}
	return (modify_env(ft_env, path));
}

char	**modify_env(char **ft_env, char *path)
{
	int	i;
	int	count;

	i = 0;
	if (!(count = ft_strlen_chr(path, '=')))
		return (ft_env);
	while (path != NULL && ft_env != NULL && ft_env[i] != NULL)
	{
		if (ft_strncmp(path, ft_env[i], count) == 0)
		{
			ft_env[i] = malloc(sizeof(ft_env[i]) * (ft_strlen(path) + 1));
			ft_env[i] = ft_strcpy(ft_env[i], path);
			return (ft_env);
		}
		i++;
	}
	return (add_to_env(ft_env, path));
}
