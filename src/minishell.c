/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 10:45:01 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/26 19:56:30 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

void	ft_free_tree(t_info *tree)
{
	int		i;

	i = 0;
	if (tree->left != NULL)
		ft_free_tree(tree->left);
	if (tree->right != NULL)
		ft_free_tree(tree->right);
	while (tree->arg != NULL && tree->arg[i] != NULL)
	{
		free(tree->arg[i]);
		tree->arg[i] = NULL;
		i++;
	}
	free(tree->arg);
	tree->arg = NULL;
	free(tree);
	tree = NULL;
}
