/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbisa <cbarbisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 11:25:01 by cbarbisa          #+#    #+#             */
/*   Updated: 2014/03/26 19:54:28 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

void		ft_trim_arg(char **arg)
{
	int		i;
	char	**tmp;

	i = 0;
	while (arg[i] != NULL)
		i++;
	tmp = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (arg[i] != NULL)
	{
		tmp[i] = arg[i];
		arg[i] = ft_strtrim(arg[i]);
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
