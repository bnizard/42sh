/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 18:32:25 by eseveno           #+#    #+#             */
/*   Updated: 2014/02/28 14:53:11 by eseveno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __42SH_H__
# define __42SH_H__

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


# define BUFF_SIZE 4096 


typedef struct	s_info
{
	char		*buf;
	char		**env;
	char		**arg;
	int			ret;
}				t_info;

/*
 *				42sh.c
 */
void    ft_init(t_info *my, char **env);
void    ft_copyenv(t_info *my, char **env);
char    *ft_complete(char *env);
void    ft_read(t_info *my);

/*
 *				libft/
 */
int     ft_strlen(char *s);
char    *ft_strtrim(char *s);
int 	ft_strncmp(const char *s1, const char *s2, size_t n);
void    ft_putstr(char *s);
void    ft_putendl(char *s);

#endif
