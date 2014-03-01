/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseveno <eseveno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 18:32:25 by eseveno           #+#    #+#             */
/*   Updated: 2014/03/01 18:09:39 by eseveno          ###   ########.fr       */
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
	char		*realbuf;
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
void    ft_freebuf(t_info *my);
void    ft_freearg(t_info *my);
void    ft_freeall(t_info *my);

/*
 *				libft/
 */

int     ft_strlen(char *s);
char    *ft_cust_strtrim(char const *s);
int		ft_isspace(char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int 	ft_strncmp(const char *s1, const char *s2, size_t n);
void    ft_putstr(char *s);
void    ft_putendl(char *s);
char	**ft_strsplit(char *s, char delim);

#endif
