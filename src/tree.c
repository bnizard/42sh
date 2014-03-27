/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 17:02:29 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 19:49:41 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <ftsh.h>

t_info			*ft_init_info(void)
{
	t_info		*tree;

	tree = (t_info *)malloc(sizeof(t_info));
	tree->arg = NULL;
	tree->buf = NULL;
	tree->realbuf = NULL;
	tree->env = NULL;
	tree->way = NULL;
	tree->oldway = NULL;
	tree->right = NULL;
	tree->envcpy = 0;
	tree->left = NULL;
	tree->root = tree;
	return (tree);
}

int				ft_ptrlen(char **ptr)
{
	int			i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}

char			**ft_search_tree(t_info *tree, t_info *oldtree,
						int fd1[2], char ***env)
{
	pid_t		pid;
	int			fd[2];

	pid = -1;
	if (oldtree != NULL)
		pipe(fd);
	if (tree->type == 3 || tree->type == 1)
	{
		pid = fork();
		if (pid > 0)
		{
			wait(0);
			if (oldtree != NULL && (ft_strcmp(oldtree->arg[0], ">") == 0))
				ft_op_left(oldtree, fd, fd1);
			else if (oldtree != NULL && (ft_strcmp(oldtree->arg[0], ">>") == 0))
				ft_op_left_double(oldtree, fd, fd1);
		}
		else if (pid == 0)
			ft_tree_root(tree, fd, fd1, env);
	}
	else if (tree == tree->root && (tree->type == 5 || tree->type == 4))
		*env = ft_sort(tree, env);
	return (*env);
}

void			ft_free_tab(t_tab **tab)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		while (tab[i]->data[j] != NULL)
		{
			free(tab[i]->data[j]);
			tab[i]->data[j] = NULL;
			j++;
		}
		j = 0;
		free(tab[i]->data);
		tab[i]->data = NULL;
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

t_info			*ft_create_tree(t_tab **tab)
{
	t_info		*tree;
	int			i;

	i = 0;
	tree = ft_init_info();
	while (tab[i] != NULL)
		i++;
	if ((tree = ft_set_info(tree, tab, i - 1)) == NULL)
		return (NULL);
	ft_free_tab(tab);
	return (tree);
}
