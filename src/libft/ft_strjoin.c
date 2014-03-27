/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 16:36:42 by bnizard           #+#    #+#             */
/*   Updated: 2014/03/26 19:10:22 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	tab = NULL;
	i = 0;
	j = 0;
	if (s1 && s2)
	{
		tab = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (tab == NULL)
			return (NULL);
		while (s1[i] != '\0')
		{
			tab[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			tab[i++] = s2[j++];
		tab[i] = '\0';
	}
	return (tab);
}
