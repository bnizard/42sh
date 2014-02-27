/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:34:46 by eseveno           #+#    #+#             */
/*   Updated: 2014/02/27 19:19:49 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

int		ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_read(t_info *my)
{
	write(1, "$>", 2);
	if ((my->ret = read(0, my->buf, BUFF_SIZE)) == -1)
		return ;
	if (my->ret >= 1)
		my->buf[my->ret - 1] = '\0';
	ft_putstr(my->buf);
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

void	ft_init(t_info *my, char **env)
{
	my->buf = (char*)malloc(sizeof(char) * BUFF_SIZE);
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
	}
	return (0);
}
