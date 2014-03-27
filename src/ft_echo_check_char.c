/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_check_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmellado <dmellado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 14:50:22 by dmellado          #+#    #+#             */
/*   Updated: 2014/03/26 19:55:24 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

int		check_env(char *s, char **env)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_strjoin(s, "=");
	while (env[i] && (ft_strncmp(env[i], str, ft_strlen(str))))
		i++;
	if (!env[i])
	{
		free(str);
		return (0);
	}
	else
	{
		ft_putstr(tmp = ft_coppath(env[i], ft_strlen(str)));
		free(tmp);
	}
	free(str);
	return (0);
}

int		print_env_var(char *s, int i, char **env)
{
	char	*tab;
	int		j;
	int		tmp;
	int		tmp2;

	j = 0;
	tmp = i;
	while (s[i] && s[i] != '\\' && s[i] != '$')
	{
		i++;
		j++;
	}
	if (!(tab = (char *)malloc(sizeof(char) * j)))
		return (0);
	tmp2 = j;
	j = 0;
	i = 0;
	while (j < tmp2)
		tab[j++] = s[tmp++];
	tab[j] = '\0';
	check_env(tab, env);
	free(tab);
	return (j - 1);
}

int		check_condition(char *s, int i, int value)
{
	if (value == 0)
	{
		if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c' || s[i] == 'f'
			|| s[i] == 'n' || s[i] == 'r' || s[i] == 't'
			|| s[i] == 'v' || s[i] == '\\')
			return (0);
	}
	else if (value == 1)
	{
		if (convert_octal(s, i + 1) != -1 && ft_isdigit(s[i + 1])
			&& ft_isdigit(s[i + 2])
			&& ft_isdigit(s[i + 3]))
			return (1);
	}
	else if (value == 2)
	{
		if (tool_for_hexa(s[i + 1]) != -1
			&& tool_for_hexa(s[i + 2]) != -1
			&& convert_hexa(s, i + 1) != -1)
			return (2);
	}
	return (-1);
}

int		print_char(char *s, int i, int value)
{
	if (value == 0)
	{
		ft_putchar(convert_octal(s, i + 1));
		i = i + 3;
	}
	else if (value == 1)
	{
		ft_putchar(convert_hexa(s, i + 1));
		i = i + 2;
	}
	else if (value == 2)
	{
		ft_putchar('\\');
		ft_putchar(s[i]);
	}
	return (i);
}

void	echo_putstr(char *s, char ***env)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\\')
		{
			i++;
			if (check_condition(s, i, 0) == 0)
				ft_putchar(backslash_char(s[i]));
			else if (s[i] == '0' && check_condition(s, i, 1) == 1)
				i = print_char(s, i, 0);
			else if (s[i] == 'x' && check_condition(s, i, 2) == 2)
				i = print_char(s, i, 1);
			else
				i = print_char(s, i, 2);
		}
		else if (s[i] == '$')
			i = i + print_env_var(s, i + 1, *env) + 1;
		else
			ft_putchar(s[i]);
		i++;
	}
}
