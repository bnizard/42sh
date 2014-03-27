/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:13:43 by eseveno           #+#    #+#             */
/*   Updated: 2014/03/27 18:23:41 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <ftsh.h>

char	*ft_othertilde(t_info *my, char **env)
{
	char	*c;
	char	*d;
	char	*v;
	int		i;
	int		y;

	y = 0;
	i = 1;
	d = malloc(sizeof(char) * ft_strlen(my->arg[1]));
	while (my->arg[1] != NULL && my->arg[1][i])
		d[y++] = my->arg[1][i++];
	d[y] = '\0';
	i = 0;
	while (env[i] != NULL && ft_strncmp(env[i], "HOME=", 5))
		i++;
	c = ft_coppath(env[i], 5);
	v = ft_strjoin(c, d);
	free(c);
	free(d);
	return (v);
}

char	*ft_tilde(char *newway, t_info *my, int arg, char **env)
{
	int		i;
	char	*c;

	c = NULL;
	i = 0;
	if ((!(arg)) || (my->arg[1][0] == '~' && !my->arg[1][1]))
	{
		newway = NULL;
		while (env[i] != NULL && ft_strncmp(env[i], "HOME=", 5))
			i++;
		c = ft_coppath(env[i], 5);
		return (c);
	}
	else if (my->arg[1] != NULL
			&& my->arg[1][0] == '~' && my->arg[1][1] == '/')
	{
		c = ft_othertilde(my, env);
		return (c);
	}
	return (ft_strjoin(newway, ""));
}

void	ft_go(t_info *my, int i, int arg, char ***env)
{
	int		y;
	char	*tmp;
	char	*realway;

	y = 0;
	realway = ft_tilde(my->buf, my, arg, *env);
	free(my->buf);
	if (ft_accesserror(realway, my))
	{
		chdir(realway);
		while ((*env)[y] && ft_strncmp((*env)[y], "OLDPWD=", 7))
			y++;
		tmp = (*env)[y];
		(*env)[y] = ft_strjoin("OLD", (*env)[i]);
		free(tmp);
		tmp = (*env)[i];
		free(tmp);
		(*env)[i] = getcwd(NULL, 0);
		my->oldway = (*env)[i];
		tmp = my->oldway;
		(*env)[i] = ft_strjoin("PWD=", my->oldway);
		free(tmp);
	}
	free(realway);
}

void	ft_noarg(t_info *my, char ***env)
{
	int		t[2];

	t[0] = 0;
	t[1] = ft_strlen_2d(my->arg) - 1;
	if (!(t[1] > 0))
	{
		while ((*env)[t[0]] && (ft_strncmp((*env)[t[0]], "HOME=", 5) != 0))
			t[0]++;
		my->buf = ft_coppath((*env)[t[0]], 5);
		while ((*env)[t[0]] && (ft_strncmp((*env)[t[0]], "PWD=", 4) != 0))
			t[0]++;
		ft_go(my, t[0], t[1], env);
	}
	else
	{
		while ((*env)[t[0]] && (ft_strncmp((*env)[t[0]], "OLDPWD=", 7) != 0))
			t[0]++;
		my->buf = ft_coppath((*env)[t[0]], 7);
		t[0] = 0;
		while ((*env)[t[0]] && (ft_strncmp((*env)[t[0]], "PWD=", 4) != 0))
			t[0]++;
		ft_go(my, t[0], t[1], env);
	}
}

char	**ft_cd(t_info *my, char ***env)
{
	int		i;
	int		arg;
	char	*tmp;
	char	*tmp2;

	i = 0;
	ft_pwd_error(env);
	arg = ft_strlen_2d(my->arg);
	if ((arg - 1) >= 1 && my->arg[1][0] != '-')
	{
		while ((*env)[i] && (ft_strncmp((*env)[i], "PWD=", 4)))
			i++;
		tmp = ft_coppath((*env)[i], 4);
		tmp2 = ft_strjoin(tmp, "/");
		free(tmp);
		tmp = NULL;
		my->buf = ft_strjoin(tmp2, my->arg[1]);
		free(tmp2);
		tmp2 = NULL;
		ft_go(my, i, arg, env);
	}
	else if ((!(arg - 1)) || (my->arg[1][0] == '-' && !my->arg[1][1]))
		ft_noarg(my, env);
	return (NULL);
}
