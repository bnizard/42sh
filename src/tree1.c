/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:27:18 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 19:49:37 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <ftsh.h>

static void		ft_set_node1(t_info *tree, t_tab **arg, int i)
{
	int			j;

	j = 0;
	tree->right = (t_info *)malloc(sizeof(t_info));
	tree->right->arg = (char **)malloc(sizeof(char *) * \
			(ft_ptrlen(arg[i + 1]->data) + 1));
	while (arg[i + 1]->data[j] != NULL)
	{
		tree->right->arg[j] = (char *)malloc(sizeof(char) * \
				ft_strlen(arg[i + 1]->data[j]) + 1);
		tree->right->arg[j] = ft_strcpy(tree->right->arg[j], \
				arg[i + 1]->data[j]);
		j++;
	}
	tree->right->arg[j] = NULL;
	tree->right->type = arg[i + 1]->type;
	tree->right->root = tree->root;
	tree->right->left = NULL;
	tree->right->right = NULL;
	tree->left = (t_info *)malloc(sizeof(t_info));
	tree->left->arg = NULL;
	tree->left->root = tree->root;
	tree->left->left = NULL;
	tree->left->right = NULL;
}

static void		ft_set_node2(t_info *tree, t_tab **arg, int i)
{
	int			j;

	j = 0;
	if (i == 0 && arg[i + 2] != NULL && arg[i + 2]->type != 3
			&& arg[i + 2]->type != 1)
	{
		j = 0;
		tree->left->arg = (char **)malloc(sizeof(char *) * \
				(ft_ptrlen(arg[i + 2]->data) + 1));
		while (arg[i + 2]->data[j] != NULL)
		{
			tree->left->arg[j] = (char *)malloc(sizeof(char) * \
						ft_strlen(arg[i + 2]->data[j]) + 1);
			tree->left->arg[j] = ft_strcpy(tree->left->arg[j], \
					arg[i + 2]->data[j]);
			j++;
		}
		tree->left->arg[j] = NULL;
		tree->left->type = arg[i + 2]->type;
	}
}

void			ft_set_node(t_info *tree, t_tab **arg, int i)
{
	int			j;

	j = 0;
	ft_set_node1(tree, arg, i);
	tree->arg = (char **)malloc(sizeof(char *) * \
			(ft_ptrlen(arg[i]->data) + 1));
	while (arg[i]->data[j] != NULL)
	{
		tree->arg[j] = malloc(sizeof(char) * ft_strlen(arg[i]->data[j]) + 1);
		tree->arg[j] = ft_strcpy(tree->arg[j], arg[i]->data[j]);
		j++;
	}
	tree->arg[j] = NULL;
	tree->type = arg[i]->type;
	ft_set_node2(tree, arg, i);
}

void			ft_op_left(t_info *oldtree, int *fd, int *fd1)
{
	int		ret;

	ret = 0;
	close(fd[1]);
	dup2(fd[0], 0);
	if (oldtree->left->type == 6)
		fd[1] = open(oldtree->left->arg[0], O_CREAT \
				| O_TRUNC | O_WRONLY, 0666);
	else if (oldtree->right->type == 6)
		fd[1] = open(oldtree->right->arg[0], O_CREAT \
				| O_TRUNC | O_WRONLY, 0666);
	if (fd[1] != -1)
	{
		dup2(fd[1], 1);
		oldtree->buf = (char *)malloc(sizeof(char) * 10);
		while ((ret = read(0, oldtree->buf, 10)))
		{
			oldtree->buf[ret] = '\0';
			ft_putstr(oldtree->buf);
		}
	}
	ft_close_fd(fd, fd1);
	exit(0);
}

void			ft_op_left_double(t_info *oldtree, int *fd, int *fd1)
{
	int		ret;

	ret = 0;
	close(fd[1]);
	dup2(fd[0], 0);
	if (oldtree->left->type == 6)
		fd[1] = open(oldtree->left->arg[0], O_CREAT \
				| O_APPEND | O_WRONLY, 0666);
	else if (oldtree->right->type == 6)
		fd[1] = open(oldtree->right->arg[0], O_CREAT \
				| O_APPEND | O_WRONLY, 0666);
	if (fd[1] != -1)
	{
		dup2(fd[1], 1);
		oldtree->buf = malloc(sizeof(char) * 10);
		while ((ret = read(0, oldtree->buf, 10)))
		{
			oldtree->buf[ret] = '\0';
			ft_putstr(oldtree->buf);
		}
		free(oldtree->buf);
	}
	ft_close_fd(fd, fd1);
	exit(0);
}
