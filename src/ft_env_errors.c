/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <bdismuke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 22:32:07 by bdismuke          #+#    #+#             */
/*   Updated: 2014/03/26 21:00:40 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ftsh.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_env_file_error(char *name)
{
	ft_putstr("env: ");
	ft_putstr(name);
	ft_putendl(": No such file or directory");
}

void	ft_env_error(char *name)
{
	ft_putstr("42sh: ");
	ft_putstr(name);
	ft_putendl(": not found");
}

char	*ft_strcat(char *s1, const char *s2)
{
	char	*new_s1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new_s1 = s1;
	while (s1[i])
		i++;
	while (s2[j])
	{
		new_s1[i + j] = s2[j];
		j++;
	}
	new_s1[i + j] = '\0';
	return (new_s1);
}

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
