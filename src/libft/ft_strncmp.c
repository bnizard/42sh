/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmellado <dmellado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:58:57 by dmellado          #+#    #+#             */
/*   Updated: 2014/03/26 19:07:31 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 1;
	if (n == 0)
		return (0);
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2 && i < n)
	{
		++s1;
		++s2;
		i++;
	}
	return (*s1 - *s2);
}
