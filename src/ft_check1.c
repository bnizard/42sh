/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:38:18 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/27 11:12:03 by cbarbisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <ftsh.h>

char			*ft_quote(char c)
{
	int			i;
	static char	op[3] =

	{'"', '`', '\''};
	i = 0;
	while (i < 3)
	{
		if (c == op[i])
			return (ft_itoa(i + 8));
		i++;
	}
	return (NULL);
}

int				ft_is_op(char *str)
{
	int			i;
	static char	*op[3] =

	{"<", ">", ">>"};
	i = 0;
	while (i < 3)
	{
		if (ft_strcmp(str, op[i]) == 0)
			return (3);
		i++;
	}
	return (-1);
}

char			*ft_is_cmd(char *str, char **env)
{
	char		*path;
	struct stat	buf;

	if (stat(str, &buf) == 0 && buf.st_mode & S_IFREG & S_IXUSR)
		return (str);
	else if ((path = ft_find_path(str, env)) != NULL)
		return (path);
	return (NULL);
}

char			*ft_is_arg(char *str)
{
	if (str[0] == '-')
		return ("1");
	return (NULL);
}
