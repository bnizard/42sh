/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmellado <dmellado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 14:37:56 by dmellado          #+#    #+#             */
/*   Updated: 2014/03/26 20:58:43 by dmellado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ftsh.h>

int		ft_power(int value, int power)
{
	int		i;
	int		result;

	result = 1;
	i = 0;
	while (i < power)
	{
		result = result * value;
		i++;
	}
	return (result);
}

char	*ft_strcpy2(char *s, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * 3)))
		return (NULL);
	while (j <= 3)
	{
		tmp[j] = s[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

int		convert_octal(char *s, int i)
{
	char	*tmp;
	int		octal;
	int		decimal;
	int		k;

	k = 0;
	decimal = 0;
	tmp = ft_strcpy2(s, i);
	octal = ft_atoi(tmp);
	free(tmp);
	if (octal <= 177 && octal >= 0)
	{
		while (octal != 0)
		{
			decimal = decimal + (octal % 10) * ft_power(8, k++);
			octal = octal / 10;
		}
		return (decimal);
	}
	else
		return (-1);
}

int		tool_for_hexa(char c)
{
	if (c >= 65 && c <= 70)
		return (c - 55);
	else if (c >= 97 && c <= 102)
		return (c - 87);
	else if (ft_isdigit(c))
		return (c - '0');
	else
		return (-1);
}

int		convert_hexa(char *s, int i)
{
	int		c;
	int		hex[2];

	hex[0] = s[i];
	hex[1] = s[i + 1];
	if (tool_for_hexa(hex[0]) == -1 || tool_for_hexa(hex[1]) == -1)
		return (-1);
	c = tool_for_hexa(hex[0]) * 16 + tool_for_hexa(hex[1]);
	if (c > 127)
		return (-1);
	return (c);
}
