/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:27:44 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 19:49:31 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <ftsh.h>

int				ft_set_fd1(int fd, t_info *tree)
{
	if (tree->left->type == 6)
	{
		fd = open(tree->left->arg[0], O_WRONLY | O_TRUNC | O_CREAT, 0666);
		dup2(fd, 1);
	}
	else
	{
		fd = open(tree->right->arg[0], O_WRONLY | O_TRUNC | O_CREAT, 0666);
		dup2(fd, 1);
	}
	return (fd);
}

int				ft_set_fd2(int fd, t_info *tree)
{
	if (tree->left->type == 6)
	{
		fd = open(tree->left->arg[0], O_WRONLY | O_APPEND | O_CREAT, 0666);
		dup2(fd, 1);
	}
	else
	{
		fd = open(tree->right->arg[0], O_WRONLY | O_APPEND | O_CREAT, 0666);
		dup2(fd, 1);
	}
	return (fd);
}

int				ft_set_fd3(int fd, t_info *tree)
{
	if (tree->left->type == 6)
	{
		fd = open(tree->left->arg[0], O_RDONLY);
		dup2(fd, 0);
	}
	else
	{
		fd = open(tree->right->arg[0], O_RDONLY);
		dup2(fd, 0);
	}
	return (fd);
}

int				ft_set_fd(int fd, t_info *tree)
{
	fd = -1;
	if (ft_strcmp(tree->arg[0], ">") == 0)
		fd = ft_set_fd1(fd, tree);
	else if (ft_strcmp(tree->arg[0], ">>") == 0)
		fd = ft_set_fd2(fd, tree);
	else if (ft_strcmp(tree->arg[0], "<") == 0)
		fd = ft_set_fd3(fd, tree);
	return (fd);
}

void			ft_close_fd(int *fd, int *fd1)
{
	if (fd1[0] != -1)
		close(fd1[0]);
	if (fd[1] != -1)
		close(fd[1]);
	if (fd[0] != -1)
		close(fd[0]);
}
