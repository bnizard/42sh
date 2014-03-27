/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 18:31:14 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 18:34:44 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_read3(t_info *my, int i, char ***env)
{
	t_tab	**tab;
	t_info	*tree;
	int		fd[2];

	fd[0] = -1;
	fd[1] = -1;
	if ((tab = ft_parser(my->arg[i], (*env))) != NULL)
	{
		if ((tree = ft_create_tree(tab)) != NULL)
		{
			tree = tree->root;
			*env = ft_search_tree(tree, NULL, fd, env);
			ft_free_tree(tree);
		}
		else
		{
			ft_free_tab(tab);
			return (1);
		}
	}
	else
		return (1);
	return (0);
}

int		ft_read2(t_info *my)
{
	if (!(my->buf = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	write(1, "$>", 2);
	if ((my->ret = read(0, my->buf, BUFF_SIZE)) == -1)
		return (0);
	if (!my->ret)
		return (2);
	else if (my->ret >= 1)
		my->buf[my->ret - 1] = '\0';
	if (!(my->realbuf = ft_strtrim(my->buf)))
	{
		free(my->buf);
		my->buf = NULL;
		return (0);
	}
	return (3);
}

int		ft_read(t_info *my, char ***env)
{
	int		i;

	i = 0;
	if (ft_read2(my) != 3)
		return (ft_read2(my));
	free(my->buf);
	my->buf = NULL;
	my->arg = ft_strsplit(my->realbuf, ';');
	my->way = NULL;
	ft_trim_arg(my->arg);
	i = 0;
	while (my->arg[i] != NULL)
	{
		if (ft_read3(my, i, env) == 1)
			return (1);
		i++;
	}
	if (my->arg[i] == NULL)
		return (1);
	return (0);
}

char	*ft_coppath(char *path, int i)
{
	int		y;
	char	*c;

	if (!(c = malloc(sizeof(char) * (ft_strlen(path) - i + 1))))
		return (NULL);
	y = 0;
	while (path[i])
		c[y++] = path[i++];
	c[y] = '\0';
	return (c);
}

char	**ft_join(char **c, t_info *my)
{
	int		i;
	char	**d;

	i = 0;
	while (c[i])
		i++;
	if (!(d = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = -1;
	while (c[++i])
		d[i] = ft_strjoin(c[i], "/");
	i = 0;
	while (c[i])
	{
		free(c[i]);
		c[i] = NULL;
		c[i] = ft_strjoin(d[i], my->arg[0]);
		free(d[i]);
		d[i++] = NULL;
	}
	free(d);
	d = NULL;
	return (c);
}
