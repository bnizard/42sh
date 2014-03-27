/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:27:36 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 19:49:34 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <ftsh.h>

static void		ft_set_info2(t_info *tree, t_tab **arg, int i)
{
	i = 0;
	tree->arg = (char **)malloc(sizeof(char *) * (ft_ptrlen(arg[0]->data) + 1));
	while (arg[0]->data[i] != NULL)
	{
		tree->arg[i] = (char *)malloc(sizeof(char) * \
				ft_strlen(arg[0]->data[i]) + 1);
		tree->arg[i] = ft_strcpy(tree->arg[i], arg[0]->data[i]);
		i++;
	}
	tree->arg[i] = NULL;
	tree->type = arg[0]->type;
	tree->left = NULL;
	tree->right = NULL;
}

static int		ft_set_info1(t_info *tree, t_tab **arg, int i)
{
	if (arg[i + 1] == NULL)
	{
		ft_putendl("Parse Error");
		return (0);
	}
	ft_set_node(tree, arg, i);
	i--;
	if (i >= 0)
		ft_set_info(tree->left, arg, i);
	return (1);
}

t_info			*ft_set_info(t_info *tree, t_tab **arg, int i)
{
	while (i > 0 && arg[i]->type != 3 && arg[i]->type != 1)
		i--;
	if (arg[i] != NULL && (arg[i]->type == 3 || arg[i]->type == 1))
	{
		if (ft_set_info1(tree, arg, i) == 0)
			return (NULL);
	}
	else if (ft_isalpha(arg[0]->data[0][0]) == 1 || arg[0]->data[0][0] == '/')
	{
		ft_set_info2(tree, arg, i);
	}
	return (tree);
}

void			ft_exec_root(t_info *tree, char ***env)
{
	if (tree->left->type == 5)
		execve(tree->left->arg[0], tree->left->arg, *env);
	else if (tree->right->type == 5)
		execve(tree->right->arg[0], tree->right->arg, *env);
	else if (tree->left->type == 4)
	{
		set_builtins(tree->left, env);
		exit(0);
	}
	else if (tree->right->type == 4)
	{
		set_builtins(tree->right, env);
		exit(0);
	}
}

void			ft_tree_root(t_info *tree, int *fd, int *fd1, char ***env)
{
	if (tree == tree->root)
		fd[0] = ft_set_fd(fd[0], tree);
	else
	{
		fd1[0] = ft_set_fd(fd1[0], tree);
		dup2(fd[1], 1);
	}
	if ((fd[0] != -1 && tree == tree->root)
			|| (fd1[0] != -1 && tree != tree->root))
	{
		if (tree->left != NULL && tree->left->arg != NULL)
			ft_search_tree(tree->left, tree, fd, env);
		ft_exec_root(tree, env);
	}
	else
	{
		ft_close_fd(fd, fd1);
		exit(0);
	}
	ft_close_fd(fd, fd1);
}
