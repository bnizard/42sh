/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 12:02:39 by bnizard           #+#    #+#             */
/*   Updated: 2014/03/26 19:56:24 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

char	**ft_unsetenv(t_info *my, char ***env)
{
	int		arg;

	arg = ft_strlen_2d(my->arg);
	arg--;
	if (arg >= 1)
		ft_unset(my, *env);
	else
		ft_putendl("unsetenv: Too few arguments.");
	return (*env);
}

void	ft_unset(t_info *my, char **env)
{
	int		len;
	char	*tmp;
	int		i;

	i = 0;
	tmp = my->arg[1];
	my->arg[1] = ft_strjoin(my->arg[1], "=");
	free(tmp);
	tmp = NULL;
	len = ft_strlen(my->arg[1]);
	while (env[i] && (ft_strncmp(env[i], my->arg[1], len) != 0))
		i++;
	if (env[i])
	{
		tmp = env[i];
		while (env[i])
		{
			env[i] = env[i + 1];
			i++;
		}
		free(tmp);
		tmp = NULL;
	}
}
