/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:56:00 by eseveno           #+#    #+#             */
/*   Updated: 2014/03/22 20:28:39 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "42sh.h"

char	*ft_strtrim(char const *s)
{
	unsigned int		begin;
	unsigned int		end;
	char				*trimmed;

	if (s == NULL || !ft_space_error((char *)s))
		return (NULL);
	begin = 0;
	end = ft_strlen((char *)s) - 1;
	while (ft_isspace(s[begin]))
		begin++;
	while (begin <= end && ft_isspace(s[end]))
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
	while (i < (start + len) && s[i])
		allocation[j++] = s[i++];
	allocation[j] = '\0';
	return (allocation);
}
