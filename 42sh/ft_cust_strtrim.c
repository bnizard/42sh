/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cust_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdismuke <bdismuke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 18:23:54 by bdismuke          #+#    #+#             */
/*   Updated: 2014/03/01 18:24:09 by bdismuke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	*ft_cust_strtrim(char const *s)
{
	unsigned int		begin;
	unsigned int		end;
	char				*trimmed;

	if (s == NULL)
		return (NULL);
	begin = 0;
	end = ft_strlen((char *)s) - 1;
	while (ft_isspace(s[begin]) == 1)
		begin++;
	while (begin <= end && ft_isspace(s[end]) == 1)
		end--;
	trimmed = ft_strsub(s, begin, end + 1 - begin);
	return (trimmed);
}

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\f' || c == '\r' || c == '\v'
		|| c == ' ')
		return (1);
	else
		return (0);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*allocation;
	unsigned int	i;
	unsigned int	j;

	i = start;
		j = 0;
	allocation = malloc(sizeof(*allocation) * (len + 1));
	if (allocation == NULL || s == NULL)
		return (NULL);
	while (i < (start + len) && s[i] != '\0')
	{
		allocation[j] = s[i];
		i++;
		j++;
	}
	allocation[j] = '\0';
	return (allocation);
}
