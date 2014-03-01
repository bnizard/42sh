/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:34:46 by eseveno           #+#    #+#             */
/*   Updated: 2014/03/01 18:10:36 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

void	ft_read(t_info *my)
{
	int i;

	my->buf = (char*)malloc(sizeof(char) * BUFF_SIZE);
	i = 0;
	write(1, "$>", 2);
	if ((my->ret = read(0, my->buf, BUFF_SIZE)) == -1)
		return ;
	if (my->ret >= 1)
		my->buf[my->ret - 1] = '\0';
	my->realbuf = ft_cust_strtrim(my->buf);
	free(my->buf);
	my->arg = ft_strsplit(my->realbuf , ' ');
	return ;
}


char    *ft_complete(char *env)
{
	char    *dest;
	int     i;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(env + 1)))))
		return (NULL);
	while (env[i])
	{
		dest[i] = env[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_copyenv(t_info *my, char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	if (!(my->env = (char **)malloc(sizeof(char *) * (i + 1))))
		return ;
	i = 0;
	while (env[i])
	{
		my->env[i] = ft_complete(env[i]);
		i++;
	}
	my->env[i] = NULL;
}

void	ft_freebuf(t_info *my)
{
	free(my->realbuf);
}

void	ft_freearg(t_info *my)
{
	int i;

	i = 0;
	while (my->arg[i])
	{
		free(my->arg[i]);
		i++;
	}
	free(my->arg);
}

void	ft_freeall(t_info *my)
{
	ft_freearg(my);
	ft_freebuf(my);
}

void ft_debug(t_info *my)
{
	int i;

	i = 0;
	ft_putendl(my->buf);
}

void	ft_init(t_info *my, char **env)
{
	ft_copyenv(my, env);
}

int		main(int argc, char **argv, char **env)
{
	t_info my;

	(void)argc;
	(void)argv;
	ft_init(&my, env);
	while (1)
	{
		ft_read(&my);
		ft_freeall(&my);
		ft_debug(&my);
	}
	return (0);
}
