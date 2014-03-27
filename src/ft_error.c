/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 18:12:10 by eseveno           #+#    #+#             */
/*   Updated: 2014/03/26 21:02:56 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <ftsh.h>

int		ft_accesserror(char *newway, t_info *my)
{
	DIR *dir;

	if (access(newway, F_OK) == 1)
	{
		ft_putendl("$> File dont exist");
		return (0);
	}
	else if (access(newway, R_OK) == 1)
	{
		ft_putendl("$> Not access");
		return (0);
	}
	else if (!(dir = opendir(newway)))
	{
		ft_putstr(my->arg[1]);
		ft_putendl(" No such file or directory.");
		return (0);
	}
	closedir(dir);
	return (1);
}

void	ft_pwd_error(char ***env)
{
	int		y;
	char	*tmp;

	y = 0;
	while ((*env)[y] && (ft_strncmp((*env)[y], "PWD=", 4)))
		y++;
	if (!(*env)[y])
	{
		tmp = getcwd(NULL, 0);
		(*env)[y] = ft_strjoin("PWD=", tmp);
		free(tmp);
		(*env)[++y] = NULL;
	}
}
