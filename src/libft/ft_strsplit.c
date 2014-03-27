/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnizard <bnizard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 11:03:25 by bnizard           #+#    #+#             */
/*   Updated: 2014/03/26 19:09:12 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int		count_word(char *s, char delim)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == delim)
			i++;
		if (!(s[i]))
			return (res);
		res++;
		while (s[i] && s[i] != delim)
			i++;
	}
	return (res);
}

char	*copy_word(char *s, int *i, char delim)
{
	int		len;
	int		j;
	char	*res;

	len = 0;
	j = -1;
	while (s[*i] && s[*i] == delim)
		++(*i);
	while (s[*i + len] && s[*i + len] != delim)
		len++;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++j < len)
	{
		res[j] = s[*i];
		++(*i);
	}
	res[len] = '\0';
	return (res);
}

char	**ft_strsplit(char *s, char delim)
{
	int		nb_w;
	int		w;
	int		i;
	char	**res;

	nb_w = count_word(s, delim);
	if (!(res = (char**)malloc(sizeof(char*) * (nb_w + 1))))
		return (NULL);
	i = 0;
	w = 0;
	if (nb_w == 0)
	{
		res[0] = s;
		res[1] = NULL;
		return (res);
	}
	while (w < nb_w)
	{
		res[w] = copy_word(s, &i, delim);
		w++;
	}
	res[nb_w] = NULL;
	return (res);
}
