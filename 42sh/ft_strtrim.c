/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:56:00 by eseveno           #+#    #+#             */
/*   Updated: 2014/03/01 16:59:02 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42sh.h"

char	*ft_cust_strtrim(char const *s)
{
	unsigned	int		begin;
	unsigned	int		end;
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


int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\f' || c == '\r' || c == '\v'
		|| c == ' ')
		return (1);
	else
		return (0);
}
